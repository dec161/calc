#include "include/modes.hpp"
#include <iostream>
#include <stdexcept>

bool startsWith(const std::string& str, const std::string& start)
{
  return str.find(start) == 0;
}

std::map<std::string, Pointer<IParser> >::const_iterator findStart(const std::map<std::string, Pointer<IParser> >& map, const std::string& key)
{
  std::map<std::string, Pointer<IParser> >::const_iterator it;

  for (it = map.begin(); it != map.end(); ++it)
  {
    if (startsWith(it->first, key)) return it;
  }

  return it;
}

InteractiveMode::InteractiveMode(const Lexer& lexer, const std::map<std::string, Pointer<IParser> >& parsers, const std::string& current)
  : lexer(lexer), parsers(parsers), current(current) { }

void InteractiveMode::start()
{
  Pointer<IParser> parser = parsers[current];
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

    double result;
    std::list<Token> tokens = lexer.tokenize(input);

    try
    {
      result = parser->parse(tokens);
      std::cout << result << '\n';
    }
    catch (std::runtime_error e)
    {
      std::cout << e.what() << '\n';
    }
  }
}
