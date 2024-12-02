#pragma once
#ifndef EXPRESSIONS_HPP
#define EXPRESSIONS_HPP

#include <cmath>
#include "Pointer.hpp"

struct IExpr
{
  virtual ~IExpr() { }
  virtual double eval() const = 0;
  //double eval() const { return 0; }
};

class NumericLiteral : public IExpr
{
  private:
  	double value;
    
  public:
    NumericLiteral(double value) : IExpr(), value(value) { }
  	
    double eval() const
    {
      return value;
    }
};

class AddExpr : public IExpr
{
  private:
    Pointer<IExpr> lhs;
    Pointer<IExpr> rhs;
    
  public:
    AddExpr(const Pointer<IExpr> &lhs, const Pointer<IExpr> &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs->eval() + rhs->eval();
    }
};

class SubExpr : public IExpr
{
  private:
    Pointer<IExpr> lhs;
    Pointer<IExpr> rhs;
    
  public:
    SubExpr(const Pointer<IExpr> &lhs, const Pointer<IExpr> &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs->eval() - rhs->eval();
    }
};

class MulExpr : public IExpr
{
  private:
    Pointer<IExpr> lhs;
    Pointer<IExpr> rhs;
    
  public:
    MulExpr(const Pointer<IExpr> &lhs, const Pointer<IExpr> &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs->eval() * rhs->eval();
    }
};

class DivExpr : public IExpr
{
  private:
    Pointer<IExpr> lhs;
    Pointer<IExpr> rhs;
    
  public:
    DivExpr(const Pointer<IExpr> &lhs, const Pointer<IExpr> &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs->eval() / rhs->eval();
    }
};

class ExpExpr : public IExpr
{
  private:
    Pointer<IExpr> x;
    
  public:
    ExpExpr(const Pointer<IExpr> &x) : x(x) { }
  	
    double eval() const
    {
      return exp(x->eval());
    }
};

class LogExpr : public IExpr
{
  private:
    Pointer<IExpr> x;
    
  public:
    LogExpr(const Pointer<IExpr> &x) : x(x) { }
  	
    double eval() const
    {
      return log(x->eval());
    }
};

class SqrExpr : public IExpr
{
  private:
    Pointer<IExpr> x;
    
  public:
    SqrExpr(const Pointer<IExpr> &x) : x(x) { }
  	
    double eval() const
    {
      const double val = x->eval();
      return val * val;
    }
};

class SqrtExpr : public IExpr
{
  private:
    Pointer<IExpr> x;
    
  public:
    SqrtExpr(const Pointer<IExpr> &x) : x(x) { }
  	
    double eval() const
    {
      return sqrt(x->eval());
    }
};

#endif
