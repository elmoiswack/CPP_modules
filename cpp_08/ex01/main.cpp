#include "Span.hpp"

int main()
{
	Span sp(5);
	std::cout << std::endl;
	try
	{
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(-7);
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	Span copy(sp);
	std::cout << std::endl;
	try
	{
		std::cout << "Shortestspan" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << copy.shortestSpan() << std::endl;
		std::cout << "Longestspan" << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << copy.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;	
	Span large(100000);
	std::cout << std::endl;
	try
	{
		large.FillContainer();
		std::cout << large.shortestSpan() << std::endl;
		std::cout << large.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	Span empty(3);
	std::cout << std::endl;
	try
	{
		std::cout << empty.shortestSpan() << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	Span bruh(5);
	std::cout << std::endl;
	try
	{
		bruh.addNumber(1);
		bruh.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}