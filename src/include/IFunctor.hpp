#pragma once
#ifndef IFUNCTOR_HPP
#define IFUNCTOR_HPP

template<class Param, class Ret>
struct IFunctor
{
  virtual ~IFunctor() { };

  virtual Ret operator()(const Param) const = 0;
};

#endif
