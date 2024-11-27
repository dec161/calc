#pragma once
#ifndef DIVEXPR_HPP
#define DIVEXPR_HPP

#include "IExpr.hpp"

class DivExpr : public IExpr
{
  private:
    const IExpr &lhs;
    const IExpr &rhs;
    
  public:
    DivExpr(const IExpr &lhs, const IExpr &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs.eval() / rhs.eval();
    }
};

#endif
