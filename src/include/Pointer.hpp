#pragma once
#ifndef POINTER_HPP
#define POINTER_HPP

#include <map>
#include "ReferenceCounter.hpp"

template<class T>
class Pointer
{
  private:
    T* obj;
    
  public:
    Pointer(const Pointer& other) : obj(other.obj)
    {
      ReferenceCounter::inc(obj);
    }

  	Pointer(T* const obj = 0) : obj(obj)
  	{
      ReferenceCounter::inc(obj);
    }
	
    Pointer& operator=(Pointer other)
    {
      swap(*this, other);
      return *this;
    }

  	~Pointer()
  	{
      ReferenceCounter::dec(obj);
      if (ReferenceCounter::get(obj) < 1)
      {
        delete obj;
        ReferenceCounter::erase(obj);
      }
    }
	
    T& operator*() const { return *obj; }
    T* const operator->() const { return obj; }

    friend void swap(Pointer& first, Pointer& second)
    {
      using std::swap;
      swap(first.obj, second.obj);
    }
};

#endif
