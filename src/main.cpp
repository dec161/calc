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
            << "\tExample: calc -c 1 + 2 * 3 - 4\n"
            << "\tResult: 3\n"
            << "\n"
            << "-r\tReverse notation mode\n"
            << "\tExample: calc -r 4 3 2 * 1 + -\n"
            << "\tResult: 3\n";
}

double calculate(const Lexer& lexer, const Pointer<IParser>& parser, const std::string& src)
{
  return parser->parse(lexer.tokenize(src));
}

bool startsWith(const std::string& str, const std::string& start)
{
  return str.find(start) == 0;
}

void inputLoop()
{
  Lexer lexer;
  Pointer<IParser> parser;
  std::string current = "common";
  
  std::map<std::string, Pointer<IParser> > parsers;
  parsers["reverse"] = new ReverseParser;
  parsers["common"] = new CommonParser;
  
  while (1)
  {
    std::string input;
    
    std::cout << "(" << current << ")" << " >> ";
    getline(std::cin, input);
      
    if (startsWith("exit", input)) return;
    
    for (std::map<std::string, Pointer<IParser> >::const_iterator it = parsers.cbegin(); it != parsers.cend(); ++it)
    {
      if (startsWith(it->first, input))
	  {
        current = it->first;
        parser = it->second;
      }
	}
    
    std::cout << calculate(input) << '\n';
  }
}

void singleExpr()
{
  Lexer lexer;
  Pointer<IParser> parser;
  
  std::map<std::string, Pointer<IParser> > parsers;
  parsers["-r"] = new ReverseParser;
  parsers["-c"] = new CommonParser;
  
  std::map<std::string, Pointer<IParser> >::const_iterator it = parsers.find(std::string(argv[1]));
  if (it == parsers.cend())
  {
    printModes();
    return;
  }
}

int main(int argc, char** argv)
{
  if (argc == 2)
  {
    printUsage();
    return 1;
  }
  
  if (argc == 1)
  {
    
  }

  std::map<std::string, Pointer<IParser> >::const_iterator it = parsers.find(std::string(argv[1]));
  if (it == parsers.cend())
  {
    printModes();
    return 1;
  }

  parser = it->second;

  std::string input;

  for (int i = 2; i < argc; i++) 
  {
    input += argv[i];
    input += ' ';
  }

  std::cout << parser->parse(lexer.tokenize(input)) << '\n';
	
  return 0;
}
