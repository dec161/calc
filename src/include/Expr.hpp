#pragma once
#ifndef EXPR_HPP
#define EXPR_HPP

struct Expr
{
  virtual double eval() const = 0;
};

#endif
