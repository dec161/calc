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

  if (it->getType() == Add)
  {
    ++it;
    Pointer<IExpr> rhs = parseNumericLiteral();
    return new AddExpr(lhs, rhs);
  }

  return lhs;

  /*switch (it->getType())
  {
    case Add:
      ++it;
      Pointer<IExpr> rhs = parseNumericLiteral();
      return new AddExpr(lhs, rhs);

    *case Sub:
      ++it;
      Pointer<IExpr> rhs = parseNumericLiteral();
      return new SubExpr(lhs, rhs);*/

    /*default:
      return lhs;*/
  //}
}

Pointer<IExpr> CommonParser::parseNumericLiteral()
{
  switch (it->getType())
  {
    case Number:
      ++it;
      return new NumericLiteral(std::atof(it->getValue().c_str()));

    default:
      throw std::runtime_error("Unexpected token found: " + it->getValue());
  }
}
