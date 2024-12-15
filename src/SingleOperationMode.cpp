#include "include/modes.hpp"
#include <iostream>
#include <stdexcept>

SingleOperationMode::SingleOperationMode(const Lexer& lexer, const Pointer<IParser>& parser, const std::string& input)
  : lexer(lexer), parser(parser), input(input) { }

void SingleOperationMode::start()
{
  double result;
  try
  {
    result = parser->parse(lexer.tokenize(input));
    std::cout << result << '\n';
  }
  catch (std::runtime_error e)
  {
    std::cout << e.what() << '\n';
  }
}
