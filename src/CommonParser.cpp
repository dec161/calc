#include <stdexcept>
#include <cstdlib>
#include "include/parsers.hpp"

double CommonParser::parse(const std::list<Token>& tokens)
{
  it = tokens.begin();
  end = tokens.end();

  return parseExpr()->eval();
}

Pointer<IExpr> CommonParser::parseExpr()
{
  return parseAddExpr();
}

Pointer<IExpr> CommonParser::parseAddExpr()
{
  Pointer<IExpr> lhs = parseNumericLiteral();
  Pointer<IExpr> rhs;


  switch (it->getType())
  {
    case Add:
      ++it;
      rhs = parseExpr();
      return new AddExpr(lhs, rhs);

    case Sub:
      ++it;
      rhs = parseExpr();
      return new SubExpr(lhs, rhs);

    default:
      return lhs;
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
