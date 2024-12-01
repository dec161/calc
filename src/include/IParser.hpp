#pragma once
#ifndef IPARSER_HPP
#define IPARSER_HPP

#include "expressions/IExpr.hpp"
#include "Token.hpp"

struct IParser
{
  virtual ~IParser() { }
  virtual IExpr parse(const std::list<Token>&) const = 0;
};

#endif
