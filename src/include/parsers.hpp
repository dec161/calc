#pragma once
#ifndef PARSERS_HPP
#define PARSERS_HPP

#include "Pointer.hpp"
#include "Token.hpp"
#include "expressions.hpp"
#include <stack>
#include <list>

struct IParser
{
  virtual ~IParser() { }
  virtual double parse(const std::list<Token>&) = 0;
};

class ReverseParser : public IParser
{
  private:
    std::stack<Pointer<IExpr> > expr;

    void pushUnaryExpr(TokenType);
    void pushBinaryExpr(TokenType);

  public:
    double parse(const std::list<Token>&);
};

#endif
