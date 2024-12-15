#include "include/Lexer.hpp"
#include "include/parsers.hpp"
#include "include/modes.hpp"
#include <iostream>

void printHelp()
{
  std::cout << "Usage:\n"
            << "calc [ -h ]\n"
            << "calc -c <expression>\n"
            << "calc -r <expression>\n\n"
            << "-c\tCommon notation\n"
            << "\tExample: calc -c 1 + 2 * 3 - 4\n"
            << "\tResult: 3\n"
            << "\n"
            << "-r\tReverse notation\n"
            << "\tExample: calc -r 4 3 2 * 1 + -\n"
            << "\tResult: 3\n";
}

std::string reduce(char** begin, char** end)
{
  std::string ret;
  for (char** i = begin; i < end; i++)
  {
    ret += *i;
    ret += ' ';
  }
  return ret;
}

int main(int argc, char** argv)
{
  if (argc == 2)
  {
    printHelp();
    return 0;
  }

  Pointer<IMode> mode;

  std::map<std::string, Pointer<IParser> > parsers;

  if (argc == 1)
  {
    parsers["common"] = new CommonParser;
    parsers["reverse"] = new ReverseParser;

    mode = new InteractiveMode(Lexer(), parsers, parsers.begin()->first);
  }
  else
  {
    parsers["-c"] = new CommonParser;
    parsers["-r"] = new ReverseParser;

    std::map<std::string, Pointer<IParser> >::const_iterator it = parsers.find(std::string(argv[1]));
    if (it == parsers.end())
    {
      printHelp();
      return 1;
    }

    mode = new SingleOperationMode(Lexer(), it->second, reduce(argv + 2, argv + argc));
  }

  mode->start();

  return 0;
}
