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

class CommonParser : public IParser
{
  private:
    std::list<Token>::const_iterator it;
    std::list<Token>::const_iterator end;
    
    void init(const std::list<Token>&);
    Pointer<IExpr> parseExpr();
    Pointer<IExpr> parseAddExpr();
    Pointer<IExpr> parseMulExpr();
    Pointer<IExpr> parseUnaryExpr();
    Pointer<IExpr> parseNumericLiteral();

  public:
    double parse(const std::list<Token>&);
};

#endif
