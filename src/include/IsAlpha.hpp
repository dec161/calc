#pragma once
#ifndef ISALPHA_HPP
#define ISALPHA_HPP

#include "IFunctor.hpp"

struct IsAlpha : public IFunctor<char, bool>
{
  bool operator()(const char c) const
  {
    return isalpha(c);
  }
};

#endif
