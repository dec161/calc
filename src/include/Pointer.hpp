#pragma once
#ifndef POINTER_HPP
#define POINTER_HPP

#include <map>
#include "ReferenceCounter.hpp"

template<class T>
class Pointer
{
  private:
    T *const obj;

    Pointer& operator=(const Pointer&);
	
    void addPtr()
    {
      ReferenceCounter::inc(obj);
    }

    void delPtr()
    {
      ReferenceCounter::dec(obj);
      if (ReferenceCounter::get(obj) < 1)
      {
        delete obj;
        ReferenceCounter::erase(obj);
      }
    }
    
  public:
    Pointer(const Pointer &other) : obj(other.obj)
    {
      addPtr();
    }

  	Pointer(T *const obj = 0) : obj(obj)
  	{
      addPtr();
    }
	
  	~Pointer()
  	{
  	  delPtr();
    }
	
    T& operator*() const { return *obj; }
    T *const operator->() const { return obj; }
};

#endif
