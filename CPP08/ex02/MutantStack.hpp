#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack();
	MutantStack(const MutantStack &copy);
	~MutantStack();

	MutantStack &operator=(const MutantStack &copy);

	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"