#pragma once
#ifndef MODES_HPP
#define MODES_HPP

#include "Lexer.hpp"
#include "parsers.hpp"
#include "Pointer.hpp"

struct IMode
{
  virtual ~IMode() { }
  virtual void start() = 0;
};

class SingleOperationMode : public IMode
{
  private:
    Lexer lexer;
    Pointer<IParser> parser;
    std::string input;

  public:
    SingleOperationMode(const Lexer&, const Pointer<IParser>&, const std::string&);
    void start();
};

class InteractiveMode : public IMode
{
  private:
    Lexer lexer;
    std::map<std::string, Pointer<IParser> > parsers;
    std::string current;

  public:
    InteractiveMode(const Lexer&, const std::map<std::string, Pointer<IParser> >&, const std::string&);
    void start();
};

#endif
