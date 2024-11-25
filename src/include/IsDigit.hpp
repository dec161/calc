#pragma once
#ifndef ISDIGIT_HPP
#define ISDIGIT_HPP

struct IsDigit : public IPredicate
{
  inline bool operator()(const char c) const
  {
    return isdigit(c);
  }
};

#endif

