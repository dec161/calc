#include <stdexcept>
#include <cstdlib>
#include "include/parsers.hpp"

void CommonParser::init(const std::list<Token>& tokens)
{
  it = tokens.begin();
  end = tokens.end();
}

double CommonParser::parse(const std::list<Token>& tokens)
{
  init(tokens);
  return parseExpr()->eval();
}

Pointer<IExpr> CommonParser::parseExpr()
{
  return parseAddExpr();
}

Pointer<IExpr> CommonParser::parseAddExpr()
{
  Pointer<IExpr> lhs = parseMulExpr();
  Pointer<IExpr> rhs;

  switch (it->getType())
  {
    case Add:
      ++it;
      rhs = parseAddExpr();
      return new AddExpr(lhs, rhs);

    case Sub:
      ++it;
      rhs = parseAddExpr();
      return new SubExpr(lhs, rhs);

    default:
      return lhs;
  }
}

Pointer<IExpr> CommonParser::parseMulExpr()
{
  Pointer<IExpr> lhs = parseUnaryExpr();
  Pointer<IExpr> rhs;
  
  switch (it->getType())
  {
    case Mul:
      ++it;
      rhs = parseMulExpr();
      return new MulExpr(lhs, rhs);

    case Div:
      ++it;
      rhs = parseMulExpr();
      return new DivExpr(lhs, rhs);

    default:
      return lhs;
  }
}

Pointer<IExpr> CommonParser::parseUnaryExpr()
{
  switch (it->getType())
  {
  	case Exp:
  	  ++it;
  	  return new ExpExpr(parseUnaryExpr());
  	  
  	case Log:
  	  ++it;
  	  return new LogExpr(parseUnaryExpr());
  	
    case Sqr:
      ++it;
      return new SqrExpr(parseUnaryExpr());
      
    case Sqrt:
      ++it;
      return new SqrtExpr(parseUnaryExpr());
    
    default:
      return parseNumericLiteral();
  }
}

Pointer<IExpr> CommonParser::parseNumericLiteral()
{
  switch (it->getType())
  {
    case Number:
      return new NumericLiteral(std::atof((it++)->getValue().c_str()));

    default:
      throw std::runtime_error("Unexpected token found: " + it->getValue());
  }
}
