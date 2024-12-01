#pragma once
#ifndef SUBEXPR_HPP
#define SUBEXPR_HPP

#include "IExpr.hpp"

class SubExpr : public IExpr
{
  private:
    const IExpr &lhs;
    const IExpr &rhs;
    
  public:
    SubExpr(const IExpr &lhs, const IExpr &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs.eval() - rhs.eval();
    }
};

#endif
