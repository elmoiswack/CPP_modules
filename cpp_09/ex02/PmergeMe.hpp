#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> _vecarr;
	std::deque<int> _deqarr;
	unsigned int _vectime;
	unsigned int _deqtime;
public:
	PmergeMe();
	PmergeMe(PmergeMe &in);
	PmergeMe& operator=(PmergeMe &in);
	~PmergeMe();

	void ParseNumbers(char *arr[]);
	template <typename T> void AddNumber(T container, char *argv[]);

	void Merge();

	class InvalidNumbersException : public std::exception
	{
		const char* what() const throw();
	};
};
