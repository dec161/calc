#pragma once
#ifndef IPREDICATE_HPP
#define IPREDICATE_HPP

struct IPredicate
{
  virtual bool operator()(const char) const = 0;
};

#endif
