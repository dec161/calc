#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include <iostream>

void printUsage()
{
  std::cout << "Usage:\n"
            << "calc MODE EXPRESSION\n";
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
    printUsage();
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
