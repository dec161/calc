#pragma once
#ifndef REFERENCECOUNTER_HPP
#define REFERENCECOUNTER_HPP

#include <map>

class ReferenceCounter
{
	private:
		std::map<void* const, int> counter;
		static ReferenceCounter* instance;

		ReferenceCounter() { }
		~ReferenceCounter() { }
    ReferenceCounter(const ReferenceCounter&);
    ReferenceCounter& operator=(const ReferenceCounter&);

    static ReferenceCounter& getInstance()
    {
      if (instance == 0) instance = new ReferenceCounter();
      return *instance;
    }

	public:
    static void destruct()
    {
      delete instance;
      instance = 0;
    }

		static int get(void* const ref)
		{
			return getInstance().counter[ref];
		}

    static void inc(void* const ref)
    {
      ++getInstance().counter[ref];
    }

    static void dec(void* const ref)
    {
      --getInstance().counter[ref];
    }

    static void erase(void* const ref)
    {
      getInstance().counter.erase(ref);
    }
};

#endif
