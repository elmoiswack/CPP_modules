#pragma once

#include <iostream>
#include <algorithm>

class PmergeMe
{
private:
	
public:
	PmergeMe();
	PmergeMe(PmergeMe &in);
	PmergeMe& operator=(PmergeMe &in);
	~PmergeMe();

	void ParseNumbers(char *arr[]);


	class InvalidNumbersException : public std::exception
	{
		const char* what() const throw();
	};
};

