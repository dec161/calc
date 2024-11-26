#pragma once
#ifndef ISALPHA_HPP
#define ISALPHA_HPP

#include "IPredicate.hpp"

struct IsAlpha : public IPredicate
{
  bool operator()(const char) const;
};

inline bool IsAlpha::operator()(const char c) const
{
  return isalpha(c);
}

#endif
