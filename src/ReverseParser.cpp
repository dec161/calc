#include "include/parsers.hpp"
#include "include/expressions.hpp"
#include <stdexcept>
#include <cstdlib>

void ReverseParser::pushUnaryExpr(TokenType type)
{
  if (expr.size() < 1)
  {
    throw std::runtime_error("Not enough arguments supplied");
  }

  Pointer<IExpr> e;
  Pointer<IExpr> x = expr.top();
  expr.pop();

  switch (type)
  {
    case Exp:
      e = new ExpExpr(x);
      break;

    case Log:
      e = new LogExpr(x);
      break;

    case Sqr:
      e = new SqrExpr(x);
      break;
    
    case Sqrt:
      e = new SqrtExpr(x);
      break;
  }

  expr.push(e);
}

void ReverseParser::pushBinaryExpr(TokenType type)
{
  if (expr.size() < 2)
  {
    throw std::runtime_error("Not enough arguments supplied");
  }

  Pointer<IExpr> e;
  Pointer<IExpr> lhs = expr.top();
  expr.pop();
  Pointer<IExpr> rhs = expr.top();
  expr.pop();

  switch (type)
  {
    case Add:
      e = new AddExpr(lhs, rhs);
      break;

    case Sub:
      e = new SubExpr(lhs, rhs);
      break;

    case Mul:
      e = new MulExpr(lhs, rhs);
      break;
    
    case Div:
      e = new DivExpr(lhs, rhs);
      break;
  }

  expr.push(e);
}

double ReverseParser::parse(const std::list<Token> &tokens)
{
  for (std::list<Token>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
  {
    switch (it->type)
    {
      case Undefined:
        throw std::runtime_error("Unexpected token found: " + it->value);
        break;

      case Number:
        expr.push(Pointer<IExpr>(new NumericLiteral(std::atof(it->value.c_str()))));
        break;

      case Exp:
      case Log:
      case Sqr:
      case Sqrt:
        pushUnaryExpr(it->type);
        break;

      case Add:
      case Sub:
      case Mul:
      case Div:
        pushBinaryExpr(it->type);
        break;
    }
  }
  return expr.top()->eval();
}
