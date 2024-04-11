#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <limits>

class Span
{
private:
	std::multiset<int> _arr;
	unsigned int _size;
	unsigned int _last;
public:
	Span();
	Span(unsigned int N);
	Span(Span &in);
	Span& operator=(Span &in);
	~Span();

	void addNumber(int numb);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void FillContainer();

	class TooManyNumbException : public std::exception
	{
		const char *what() const throw();
	};

	class NoSpanFoundException : public std::exception
	{
		const char *what() const throw();
	};
};
