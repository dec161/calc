#pragma once
#ifndef LEXER_HPP
#define LEXER_HPP

#include <map>
#include <list>
#include "Token.hpp"

class Lexer
{
  private:
    std::map<std::string, TokenType> keywords;

  public:
    Lexer();
    std::list<Token> tokenize(const std::string&);
};

#endif
