#pragma once
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum TokenType
{
  Undefined,
  Number,
  Add,
  Sub,
  Mul,
  Div,
  Exp,
  Log,
  Root
};

struct Token
{
  const TokenType type;
  const std::string value;

  Token(TokenType type, const std::string &value) : type(type), value(value) { };
};

#endif
