#pragma once
#ifndef POINTER_HPP
#define POINTER_HPP

#include <map>
#include <iostream>

static std::map<void *const, int> refCount;

class ReferenceCounter
{
	private:
		std::map<void *const, int> counter;
		static ReferenceCounter *const instance;
		
		ReferenceCounter() { }
		
	public:
		~ReferenceCounter() { delete instance; }
		ReferenceCounter& 
}

template<class T>
class Pointer
{
  private:
	T *const obj;
	
	void addPtr()
    {
      if (refCount.find(obj) == refCount.end())
      {
        refCount[obj] = 0;
      }
      refCount[obj]++;
    }

    void delPtr()
    {
      if (refCount.find(obj) == refCount.end())
      {
      	std::cout << obj << " counter not found from destructor\n";
      	return;
	  }
    	
      refCount[obj]--;
      if (refCount[obj] < 1)
      {
        delete obj;
        refCount.erase(obj);
      }
    }
    
  public:
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
