#pragma once
#ifndef ISDIGIT_HPP
#define ISDIGIT_HPP

#include "Functor.hpp"

struct IsDigit : public Functor<char, bool>
{
  bool operator()(const char c) const
  {
    return isdigit(c);
  }
};

#endif
