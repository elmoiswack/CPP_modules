#pragma once

#include <iostream>
#include <iterator>
#include <stack>

template <typename T,  class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
private:
	/* data */
public:
	MutantStack(/* args */);
	MutantStack(MutantStack &in);
	MutantStack& operator=(MutantStack &in);
	~MutantStack();


};
