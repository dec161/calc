#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

int main()
{
  Pointer<IParser> parser;
  Lexer lexer;
  std::list<Token> tokens;

  std::string testReverse = "1 2 + sqr";
  std::string testCommon = "1 + 2";

  /*parser = new ReverseParser;
  tokens = lexer.tokenize(testReverse);
  std::cout << "Input: " << testReverse << '\n';
  std::cout << "Result: " << parser->parse(tokens) << '\n';*/

  parser = new CommonParser;
  tokens = lexer.tokenize(testCommon);
  std::cout << "Input: " << testCommon << '\n';
  std::cout << "Result: " << parser->parse(tokens) << '\n';

  return 0;
}
