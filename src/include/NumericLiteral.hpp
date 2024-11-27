#pragma once
#ifndef NUMERICLITERAL_HPP
#define NUMERICLITERAL_HPP

#include "IExpr.hpp"

class NumericLiteral : public IExpr
{
  private:
  	double value;
    
  public:
    NumericLiteral(const std::string&);
  	
    double eval() const
    {
      return value;
    }
};

#endif
