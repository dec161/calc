#pragma once
#ifndef ISALPHA_HPP
#define ISALPHA_HPP

struct IsAlpha : public IPredicate
{
  inline bool operator()(const char c) const
  {
    return isalpha(c);
  }
}

#endif

