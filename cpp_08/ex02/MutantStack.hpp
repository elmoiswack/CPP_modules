#pragma once

#include <iostream>
#include <iterator>
#include <stack>

template <typename T,  class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack()
	{
		std::cout << "MutantStack default constructor is called!" << std::endl;
	};
	//MutantStack(MutantStack &in);
	//MutantStack& operator=(MutantStack &in);
	~MutantStack() 
	{
		std::cout << "MutantStack default deconstructor is called!" << std::endl;
	};

	typedef typename Container::iterator iterator;

	iterator begin()
	{
		return (this->c.begin());
	}

	iterator end()
	{
		return (this->c.end());
	}


};
