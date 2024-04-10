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

unsigned int	Span::shortestSpan()
{
	if (this->_last == 0 || this->_last == 1)
		throw (NoSpanFoundException());

	int	shortSpan = 2147483647;
	std::multiset<int>::iterator begin = this->_arr.begin();
	std::multiset<int>::iterator end = this->_arr.begin();
	end++;

	for (; end != this->_arr.end(); end++)
	{
		if ((*end - *begin) < shortSpan)
			shortSpan = *end - *begin;
		begin++;
	}
	return (static_cast<unsigned int>(shortSpan));
}

unsigned int Span::longestSpan()
{
	if (this->_last == 0 || this->_last == 1)
		throw (NoSpanFoundException());

	int	longSpan ;
	std::multiset<int>::iterator begin = this->_arr.begin();
	std::multiset<int>::iterator endd = this->_arr.end();

	endd--;
	longSpan = *endd - *begin;
	return (static_cast<unsigned int>(longSpan));
}

void Span::FillContainer()
{
	srand(time(NULL));
	for (unsigned int i = this->_last; i < (this->_size); i++)
	{
		int numb = rand();
		this->addNumber(numb);
	}		
}