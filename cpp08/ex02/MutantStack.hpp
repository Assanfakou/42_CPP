#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
		MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other){}
		MutantStack &operator=(const MutantStack &other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack() {}
};

#endif
