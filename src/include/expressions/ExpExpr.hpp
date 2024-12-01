#pragma once
#ifndef EXPEXPR_HPP
#define EXPEXPR_HPP

#include <cmath>
#include "IExpr.hpp"

class ExpExpr : public IExpr
{
  private:
    const IExpr &x;
    
  public:
    ExpExpr(const IExpr &x) : x(x) { }
  	
    double eval() const
    {
      return exp(x.eval());
    }
};

#endif
