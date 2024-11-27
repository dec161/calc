#pragma once
#ifndef SQRTEXPR_HPP
#define SQRTEXPR_HPP

#include <cmath>
#include "IExpr.hpp"

class SqrtExpr : public IExpr
{
  private:
    const IExpr &x;
    
  public:
    SqrExpr(const IExpr &x) : x(x) { }
  	
    double eval() const
    {
      return sqrt(x.eval());
    }
};

#endif
