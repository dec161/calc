#pragma once
#ifndef ADDEXPR_HPP
#define ADDEXPR_HPP

#include "IExpr.hpp"

class AddExpr : public IExpr
{
  private:
    const IExpr &lhs;
    const IExpr &rhs;
    
  public:
    AddExpr(const IExpr &lhs, const IExpr &rhs) : lhs(lhs), rhs(rhs) { }
  	
    double eval() const
    {
      return lhs.eval() + rhs.eval();
    }
};

#endif
