#pragma once
#ifndef ISALPHA_HPP
#define ISALPHA_HPP

#include "Functor.hpp"

struct IsAlpha : public Functor<char, bool>
{
  bool operator()(const char c) const
  {
    return isalpha(c);
  }
};

#endif
