#include <stdexcept>
#include <cstdlib>
#include "include/parsers.hpp"
#include "include/expressions.hpp"

Pointer<IExpr> createUnaryExpr(TokenType type, const Pointer<IExpr>& x)
{
  switch (type)
  {
    case Exp:
      return new ExpExpr(x);

    case Log:
      return new LogExpr(x);

    case Sqr:
      return new SqrExpr(x);
    
    case Sqrt:
      return new SqrtExpr(x);
  }
}

Pointer<IExpr> createBinaryExpr(TokenType type, const Pointer<IExpr>& lhs, const Pointer<IExpr>& rhs)
{
  switch (type)
  {
    case Add:
      return new AddExpr(lhs, rhs);

    case Sub:
      return new SubExpr(lhs, rhs);

    case Mul:
      return new MulExpr(lhs, rhs);
    
    case Div:
      return new DivExpr(lhs, rhs);
  }
}

void ReverseParser::pushUnaryExpr(TokenType type)
{
  if (expr.size() < 1)
  {
    throw std::runtime_error("Not enough arguments supplied");
  }
  
  Pointer<IExpr> x = expr.top();
  expr.pop();

  expr.push(createUnaryExpr(type, x));
}

void ReverseParser::pushBinaryExpr(TokenType type)
{
  if (expr.size() < 2)
  {
    throw std::runtime_error("Not enough arguments supplied");
  }

  Pointer<IExpr> lhs = expr.top();
  expr.pop();
  Pointer<IExpr> rhs = expr.top();
  expr.pop();

  expr.push(createBinaryExpr(type, lhs, rhs));
}

double ReverseParser::parse(const std::list<Token>& tokens)
{
  for (std::list<Token>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
  {
    switch (it->getType())
    {
      case Undefined:
        throw std::runtime_error("Unexpected token found: " + it->getValue());

      case Number:
        expr.push(Pointer<IExpr>(new NumericLiteral(std::atof(it->getValue().c_str()))));
        break;

      case Exp:
      case Log:
      case Sqr:
      case Sqrt:
        pushUnaryExpr(it->getType());
        break;

      case Add:
      case Sub:
      case Mul:
      case Div:
        pushBinaryExpr(it->getType());
        break;
    }
  }

  return expr.top()->eval();
}
