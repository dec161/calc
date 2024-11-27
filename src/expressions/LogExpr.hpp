#pragma once
#ifndef LOGEXPR_HPP
#define LOGEXPR_HPP

#include <cmath>
#include "IExpr.hpp"

class LogExpr : public IExpr
{
  private:
    const IExpr &x;
    
  public:
    LogExpr(const IExpr &x) : x(x) { }
  	
    double eval() const
    {
      return log(x.eval());
    }
};

#endif
