#pragma once
#ifndef PARSER_HPP
#define PARSER_HPP

#include "IExpr.hpp"
#include "Token.hpp"

struct Parser
{
  virtual IExpr parse(std::list<Token>) const;
};

#endif
