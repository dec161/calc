#pragma once
#ifndef NUMERICLITERAL_HPP
#define NUMERICLITERAL_HPP

#include <cstdlib>
#include "IExpr.hpp"

class NumericLiteral : public IExpr
{
  private:
  	const double value;
    
  public:
    NumericLiteral(const std::string& str) : value(atof(str.c_str())) { }
  	
    double eval() const
    {
      return value;
    }
};

#endif
