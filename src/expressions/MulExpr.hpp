#pragma once
#ifndef MULEXPR_HPP
#define MULEXPR_HPP

#include "IExpr.hpp"

class MulExpr : public IExpr
{
  private:
    const IExpr &lhs;
    const IExpr &rhs;
    
  public:
    MulExpr(const IExpr &lhs, const IExpr &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs.eval() * rhs.eval();
    }
};

#endif
