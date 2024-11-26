#pragma once
#ifndef ISDIGIT_HPP
#define ISDIGIT_HPP

#include "IFunctor.hpp"

struct IsDigit : public IFunctor<char, bool>
{
  bool operator()(const char c) const
  {
    return isdigit(c);
  }
};

#endif
