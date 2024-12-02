#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

int main()
{
  Pointer<IParser> parser;
  Lexer lexer;

  std::string test = "1 2 + sqr";
  parser = new ReverseParser;

  std::list<Token> tokens = lexer.tokenize(test);

  std::cout << "Input: " << test << '\n';
  std::cout << "Result: " << parser->parse(tokens) << '\n';

  return 0;
}
