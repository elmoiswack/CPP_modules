#include "Span.hpp"

Span::Span()
{
	std::cout << "Default constructor is called but no size is passed!" << std::endl;
	this->_size = 0;
	this->_last = 0;
}

Span::Span(unsigned int N)
{
	std::cout << "Default constructor is called!" << std::endl;
	this->_size = N;
	this->_last = 0;
}

Span::Span(Span &in)
{
	std::cout << "Copy constructor is called!" << std::endl;
	*this = in;
}

Span& Span::operator=(Span &in)
{
	std::cout << "Operator overload '=' is called!" << std::endl;
	if (this == &in)
		return (*this);
	std::multiset<int>::iterator ptr;
	
	this->_size = in._size;
	for (ptr = in._arr.begin(); ptr != in._arr.end(); ptr++)
	{
		this->_arr.insert(*ptr);
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

void Span::addNumber(int numb)
{
	if (this->_last == this->_size)
		throw (TooManyNumbException());
	this->_arr.insert(numb);
	this->_last += 1;
}

int	Span::shortestSpan()
{
	if (this->_last == 0 || this->_last == 1)
		throw (NoSpanFoundException());

	int	shortSpan = 2147483646;
	int	begin_int;
	std::multiset<int>::iterator begin = this->_arr.begin();
	std::multiset<int>::iterator end;

	begin_int = *begin;
	for (end = this->_arr.begin(); end != this->_arr.end(); end++)
	{
		if (end == begin)
			end++;
		if ((*end - begin_int) < shortSpan)
			shortSpan = *end - begin_int;
	}
	return (shortSpan);
}

int Span::longestSpan()
{
	if (this->_last == 0 || this->_last == 1)
		throw (NoSpanFoundException());

	int	longSpan = 0;
	std::multiset<int>::iterator begin = this->_arr.begin();
	std::multiset<int>::iterator endd;

	for (endd = this->_arr.begin(); endd != this->_arr.end(); endd++)
	{
		if ((*endd - *begin) > longSpan)
			longSpan = *endd - *begin;
	}
	return (longSpan);
}