#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

void testOutput(const Pointer<IParser>& parser, const Lexer& lexer, const std::string& src, double expected)
{
  std::list<Token> tokens = lexer.tokenize(src);
  double actual = parser->parse(tokens);
  
  std::cout << "Input: " << src << '\n'
            << "Result: " << actual << '\n';
  
  if (actual != expected)
  {
    std::cout << "Test failed" << '\n'
	          << "Expected result: " << expected << '\n';
  }
}

int main()
{
  Lexer lexer;
  Pointer<IParser> parser = new CommonParser;
  std::list<Token> tokens;

  testOutput(parser, lexer, "5", 5);
  std::cout << '\n';
  testOutput(parser, lexer, "5 * 2", 10);
  std::cout << '\n';
  testOutput(parser, lexer, "5 + 3", 8);
  std::cout << '\n';
  testOutput(parser, lexer, "5 + 3 * 2", 11);
  std::cout << '\n';
  testOutput(parser, lexer, "5 * 3 + 2", 17);
  std::cout << '\n';
  testOutput(parser, lexer, "5 + 4 + 3 + 2", 14);
  std::cout << '\n';
  testOutput(parser, lexer, "5 * 4 * 3 * 2", 120);
  std::cout << '\n';
  testOutput(parser, lexer, "sqr 5", 25);
  std::cout << '\n';
  testOutput(parser, lexer, "5 * sqrt sqr 2", 10);
  std::cout << '\n';
  testOutput(parser, lexer, "(1)", 1);
  std::cout << '\n';
  testOutput(parser, lexer, "(5 + 3) * 2", 16);
  std::cout << '\n';
  testOutput(parser, lexer, "2 * (5 + 3)", 16);
  std::cout << '\n';
  testOutput(parser, lexer, "(1 + (2 + (3 * (2 + 2))))", 15);
  std::cout << '\n';
  testOutput(parser, lexer, "(1 + sqr (2 + (sqrt 4 + 3 * (2 + 2))))", 257);
  std::cout << '\n';

  return 0;
}
