#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <set>

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
	int	shortestSpan();
	int	longestSpan();

	class TooManyNumbException : public std::exception
	{
		const char *what() const throw()
		{
			return ("The maximum numbers have already been added, the number you just passed won't be included in the array!");
		}
	};

	class NoSpanFoundException : public std::exception
	{
		const char *what() const throw()
		{
			return ("No span found, either because there is only 1 number in the array or non at all!\nCall addNumber() first!");
		}
	};
};
