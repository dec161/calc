#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

int main()
{
  ReverseParser reverseParser;
  Lexer lexer;
  std::string test = "1";

  std::list<Token> tokens = lexer.tokenize(test);

  std::cout << "Tokens:\n";
  for (std::list<Token>::const_iterator it = tokens.begin(); it != tokens.end(); it++)
  {
    std::cout << it->type << ' ' << it->value << '\n';
  }
  std::cout << '\n';

  std::cout << "Result: " << reverseParser.parse(tokens) << '\n';

  return 0;
}
