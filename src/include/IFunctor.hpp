#pragma once
#ifndef IFUNCTOR_HPP
#define IFUNCTOR_HPP

template<class Parameter, class Return>
struct IFunctor
{
  virtual ~IFunctor() { };

  virtual Return operator()(const Parameter) const = 0;
};

#endif
