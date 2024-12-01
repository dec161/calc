#pragma once
#ifndef SQREXPR_HPP
#define SQREXPR_HPP

#include "IExpr.hpp"

class SqrExpr : public IExpr
{
  private:
    const IExpr &x;
    
  public:
    SqrExpr(const IExpr &x) : x(x) { }
  	
    double eval() const
    {
      const double val = x.eval();
      return val * val;
    }
};

#endif
