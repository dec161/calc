#pragma once
#ifndef ISDIGIT_HPP
#define ISDIGIT_HPP

#include "IPredicate.hpp"

struct IsDigit : public IPredicate
{
  bool operator()(const char) const;
};

inline bool IsDigit::operator()(const char c) const
{
  return isdigit(c);
}

#endif
