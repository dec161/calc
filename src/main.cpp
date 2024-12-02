#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

int main()
{
  ReverseParser reverseParser;
  Lexer lexer;
  std::string test = "1 2 + sqr";

  std::list<Token> tokens = lexer.tokenize(test);

  std::cout << "Input: " << test << '\n';
  std::cout << "Result: " << reverseParser.parse(tokens) << '\n';

  return 0;
}
