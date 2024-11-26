#include "include/Lexer.hpp"
#include "include/IsAlpha.hpp"
#include "include/IsDigit.hpp"

int countConsecutive(const IFunctor<char, bool> &functor, const std::string &str, const int start = 0)
{
  int i;
  for (i = start; functor(str[i]); i++);
  return i - start;
}

std::string getNumber(const std::string &str, const int start = 0)
{
  IsDigit digit;
  int i = start;

  int size = countConsecutive(digit, str, i);

  std::string number = str.substr(i, size);
  i += size;

  if (str[i] == '.')
  {
    number += str[i];
    i++;

    size = countConsecutive(digit, str, i);
    number += str.substr(i, size);
  }

  return number;
}

std::string getWord(const std::string &str, const int start = 0)
{
  IsAlpha alpha;
  int size = countConsecutive(alpha, str, start);
  std::string word = str.substr(start, size);

  return word;
}

Lexer::Lexer()
{
  keywords["exp"] = Exp;
  keywords["log"] = Log;
  keywords["root"] = Root;
}

std::list<Token> Lexer::tokenize(const std::string &source)
{
  std::list<Token> ret;

  int i = 0;
  while (i < source.size())
  {
    if (isspace(source[i]))
    {
      while (isspace(source[i])) i++;
      continue;
    }
  	
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
      TokenType type;
      std::string word = getWord(source, i);
      
      std::map<std::string, TokenType>::iterator it = keywords.find(word);
      type = (it == keywords.end()) ? Undefined : it->second;
      
      ret.push_back(Token(type, word));
      i += word.size();
      continue;
    }

    std::string str;
    str += source[i++];
    ret.push_back(Token(Undefined, str));
  }

  return ret;
}
