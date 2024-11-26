#pragma once
#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <list>
#include <map>

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

  Token(TokenType, const std::string&);
};

std::list<Token> tokenize(const std::string&);

#endif
