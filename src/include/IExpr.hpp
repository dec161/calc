#pragma once
#ifndef IEXPR_HPP
#define IEXPR_HPP

struct IExpr
{
  virtual double eval() const = 0;
};

#endif
