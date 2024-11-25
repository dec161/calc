#pragma once
#ifndef IPREDICATE_HPP
#define IPREDICATE_HPP

struct IPredicate
{
  virtual inline bool operator()(const char) const = 0;
};

#endif

