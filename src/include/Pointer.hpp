#pragma once
#ifndef POINTER_HPP
#define POINTER_HPP

#include <map>

template<class T>
struct Pointer
{
  private:
    static std::map<T*, int> refCount;
    T *obj;

    void addRef(T *ptr)
    {
      if (refCount.find(ptr) == refCount.end())
      {
        refCount[ptr] = 0;
      }

      refCount[ptr]++;
    }

    void delRef(T *ptr)
    {
      refCount[ptr]--;
      if (refCount[ptr] < 1)
      {
        delete ptr;
      }
    }

  public:
    Pointer(T *obj = 0) : obj(obj)
    {
      addRef(obj);
    }

    ~Pointer()
    {
      delRef(obj);
    }

    T& operator*() const { return *obj; }
    T* operator->() const { return obj; }
};

template<class T>
std::map<T*, int> Pointer<T>::refCount;

#endif
