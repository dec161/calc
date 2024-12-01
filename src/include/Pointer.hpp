#pragma once
#ifndef POINTER_HPP
#define POINTER_HPP

template<class T>
struct Pointer
{
  private:
    T *obj;

  public:
    Pointer(T *obj = 0) : obj(obj) { }
    ~Pointer() { delete obj; }

    T& operator*() const { return *obj; }
    T* operator->() const { return obj; }
};

#endif
