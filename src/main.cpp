#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

void printUsage()
{
  std::cout << "Usage:\n"
            << "calc MODE EXPRESSION\n";
}

void printModes()
{
  std::cout << "Available modes:\n"
            << "-c\tCommon notation mode\n"
            << "\tExample: 1 + 2 * 3 - 4\n"
            << "\tResult: 3\n"
            << "\n"
            << "-r\tReverse notation mode (4 3 2 * 1 + -)\n"
            << "\tExample: 4 3 2 * 1 + -\n"
            << "\tResult: 3\n"
            << "\n"
}

int main(int argc, char** argv)
{
  if (argc < 2) 
  {
    printUsage();
    return 1;
  }
	
  Lexer lexer;
  Pointer<IParser> parser;
		
  if (argv[1] == std::string("-r"))
  {
    parser = new ReverseParser;
  }
  else if (argv[1] == std::string("-c"))
  {
    parser = new CommonParser;
  }
  else
  {
    printModes();
    return 1;
  }
	
  std::string input;
	
  for (int i = 2; i < argc; i++) 
  {
    input += argv[i];
    input += ' ';
  }
	
  std::cout << parser->parse(lexer.tokenize(input)) << '\n';
	
  return 0;
}
