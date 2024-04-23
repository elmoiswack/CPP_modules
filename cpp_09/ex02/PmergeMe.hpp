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
	unsigned int _elements;
public:
	PmergeMe();
	PmergeMe(PmergeMe &in);
	PmergeMe& operator=(PmergeMe &in);
	~PmergeMe();

	void ParseNumbers(char *arr[]);
	void AddNumberToBoth(char *numb);
	void CheckDoubles(std::vector<int> container);
	
	void StartSort();
	template <typename T> void MergeInsertion(T container);

	template <typename T> void PrintContainer(T container);
	void PrintTime(double time, bool is_vec);

	class InvalidNumbersException : public std::exception
	{
		const char* what() const throw();
	};

	class DoubleNumbersException : public std::exception
	{
		const char* what() const throw();
	};
};
