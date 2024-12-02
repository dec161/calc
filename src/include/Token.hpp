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
  Sqr,
  Sqrt
};

class Token
{
  private:
    TokenType type;
    std::string value;

  public:
    Token(TokenType type, const std::string &value) : type(type), value(value) { };

    TokenType getType() const { return type; }
    const std::string& getValue() const { return value; }
};

#endif
