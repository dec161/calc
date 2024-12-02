#pragma once
#ifndef REFERENCECOUNTER_HPP
#define REFERENCECOUNTER_HPP

#include <map>

class ReferenceCounter
{
	private:
		std::map<void *const, int> counter;
		static ReferenceCounter *instance;

		ReferenceCounter() { }
		~ReferenceCounter() { }
    ReferenceCounter(const ReferenceCounter&);
    ReferenceCounter& operator=(const ReferenceCounter&);

	public:
    static void ensureInstance()
    {
      if (instance == 0) instance = new ReferenceCounter();
    }
		
    static void destruct()
    {
      delete instance;
      instance = 0;
    }

		static int get(void *const ref)
		{
      ensureInstance();
			return instance->counter[ref];
		}

    static void inc(void *const ref)
    {
      ensureInstance();
      ++(instance->counter[ref]);
    }

    static void dec(void *const ref)
    {
      ensureInstance();
      --(instance->counter[ref]);
    }

    static void erase(void *const ref)
    {
      ensureInstance();
      instance->counter.erase(ref);
    }
};

#endif
