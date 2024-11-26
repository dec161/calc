#pragma once
#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

template<class Parameter, class Return>
struct Functor
{
  virtual ~Functor() { };

  virtual Return operator()(const Parameter) const = 0;
};

#endif
