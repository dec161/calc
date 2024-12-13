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

bool startsWith(const std::string& str, const std::string& start)
{
  return str.find(start) == 0;
}

std::map<std::string, Pointer<IParser> >::const_iterator findStart(const std::map<std::string, Pointer<IParser> >& map, const std::string& key)
{
  for (std::map<std::string, Pointer<IParser> >::const_iterator it = map.begin(); it != map.end(); ++it)
  {
    if (startsWith(it->first, key)) return it;
  }
  return map.end();
}

void inputLoop()
{
  Lexer lexer;
  Pointer<IParser> parser;
  std::string current = "common";
  
  std::map<std::string, Pointer<IParser> > parsers;
  parsers["reverse"] = new ReverseParser;
  parsers["common"] = new CommonParser;
  
  parser = parsers["common"];
  
  while (1)
  {
    std::string input;
    
    std::cout << "(" << current << ")" << " >> ";
    getline(std::cin, input);
      
    if (startsWith("exit", input)) return;
    
    std::map<std::string, Pointer<IParser> >::const_iterator it = findStart(parsers, input);
    if (it != parsers.end())
    {
      current = it->first;
      parser = it->second;
      continue;
	}
    
    std::cout << parser->parse(lexer.tokenize(input)) << '\n';
  }
}

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    inputLoop();
    return 0;
  }
  
  if (argc < 3)
  {
    printUsage();
    return 1;
  }
  
  Lexer lexer;
  Pointer<IParser> parser;
  
  std::map<std::string, Pointer<IParser> > parsers;
  parsers["-r"] = new ReverseParser;
  parsers["-c"] = new CommonParser;

  std::map<std::string, Pointer<IParser> >::const_iterator it = parsers.find(std::string(argv[1]));
  if (it == parsers.end())
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
