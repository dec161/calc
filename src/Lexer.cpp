#include "include/Lexer.hpp"
#include "include/functors.hpp"

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
  keywords["sqr"] = Sqr;
  keywords["sqrt"] = Sqrt;
}

std::list<Token> Lexer::tokenize(const std::string &source) const
{
  std::list<Token> ret;

  int i = 0;
  while (i < source.size())
  {
    if (isspace(source[i]))
    {
      i++;
      continue;
    }
  	
    TokenType type;
    std::string value;

    if (source[i] == '+')
    {
      type = Add;
      value = "+";
    }
    else if (source[i] == '-')
    {
      type = Sub;
      value = "-";
    }
    else if (source[i] == '*')
    {
      type = Mul;
      value = "*";
    }
    else if (source[i] == '/')
    {
      type = Div;
      value = "/";
    }
    else if (source[i] == '(')
    {
      type = OpenParen;
      value = "(";
    }
    else if (source[i] == ')')
    {
      type = CloseParen;
      value = ")";
    }
    else if (isdigit(source[i]))
    {
      type = Number;
      value = getNumber(source, i);
    }
    else if (isalpha(source[i]))
    {
      value = getWord(source, i);
      std::map<std::string, TokenType>::const_iterator it = keywords.find(value);
      type = (it == keywords.end()) ? Undefined : it->second;
    }
    else
    {
      type = Undefined;
      value = std::string() + source[i];
    }

    i += value.size();
    Token token(type, value);
    ret.push_back(token);
  }

  ret.push_back(Token(End, "End"));
  return ret;
}
