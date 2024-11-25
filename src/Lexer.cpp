#include "include/Lexer.hpp"
#include "include/IPredicate.hpp"
#include "include/IsAlpha.hpp"
#include "include/IsDigit.hpp"
#include <map>

std::map<std::string, TokenType> keywords
{
  {"exp", Exp},
  {"log", Log},
  {"root", Root}
};

int count(const IPredicate& predicate, const std::string& str, const int start = 0)
{
  if (!predicate(str[start])) return -1;

  int i;
  for (i = start; predicate(str[i]); i++);
  return i - start;
}

std::string getNumber(const std::string& str, const int start = 0)
{
  IsDigit digit;
  int i = start;
  int size = count(digit, str, i)

  std::string number = str.substr(i, size);
  i += size;

  if (i == '.')
  {
    number += i;
    i++;

    size = count(digit, str, i);
    number += str.substr(i, size);
  }

  return number;
}

std::string getWord(const std::string& str, const int start = 0)
{
  IsAlpha alpha;
  int size = count(alpha, str, start);
  std::string word = str.substr(start, size);

  return word;
}

std::list<Token> tokenize(const std::string& source)
{
  std::list<Token> ret;

  int i = 0;
  while (i < source.size())
  {
    if (source[i] == '+')
    {
      ret.push_back(Token(Add, "+"));
      i++;
      continue;
    }

    if (source[i] == '-')
    {
      ret.push_back(Token(Sub, "-"));
      i++;
      continue;
    }

    if (source[i] == '*')
    {
      ret.push_back(Token(Mul, "*"));
      i++;
      continue;
    }

    if (source[i] == '/')
    {
      ret.push_back(Token(Div, "/"));
      i++;
      continue;
    }

    if (isdigit(source[i]))
    {
      std::string number = getNumber(source, i);
      ret.push_back(Token(Number, number));
      i += number.size();
      continue;
    }

    if (isalpha(source[i]))
    {
      std::string word = getWord(source, i);
      
      try
      {
        TokenType type = keywords[word];
      }
      catch (std::out_of_range)
      {
        return ret; // TODO: add error instead of this
      }

      ret.push_back(Token(type, word));
      i += word.size();
      continue;
    }

    // error if control gets here
  }

  return ret;
}

