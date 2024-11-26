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

inline Token::Token(TokenType type, const std::string& value) : type(type), value(value) { }

std::list<Token> tokenize(const std::string&);

#endif
