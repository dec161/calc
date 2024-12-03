#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

void testOut(const Pointer<IParser>& parser, const Lexer& lexer, const std::string& src)
{
  std::list<Token> tokens = lexer.tokenize(src);
  std::cout << "Input: " << src << '\n';
  std::cout << "Result: " << parser->parse(tokens) << '\n';
}

int main()
{
  Lexer lexer;
  std::list<Token> tokens;

  testOut(new CommonParser, lexer, "5");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "5 * 2");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "5 + 3");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "5 + 3 * 2");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "5 * 3 + 2");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "5 + 4 + 3 + 2");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "5 * 4 * 3 * 2");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "sqr 5");
  std::cout << '\n';
  testOut(new CommonParser, lexer, "5 * sqrt sqr 2");
  std::cout << '\n';

  return 0;
}
