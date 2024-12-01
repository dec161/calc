#pragma once
#ifndef FUNCTORS_HPP
#define FUNCTORS_HPP

template<class Parameter, class Return>
struct IFunctor
{
  virtual ~IFunctor() { }
  virtual Return operator()(const Parameter) const = 0;
};

struct IsAlpha : public IFunctor<char, bool>
{
  bool operator()(const char c) const
  {
    return isalpha(c);
  }
};

struct IsDigit : public IFunctor<char, bool>
{
  bool operator()(const char c) const
  {
    return isdigit(c);
  }
};

#endif
