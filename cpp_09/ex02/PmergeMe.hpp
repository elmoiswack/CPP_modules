#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> _vecsorted;
	std::vector<int> _vecarr;
	std::deque<int> _deqsorted;
	std::deque<int> _deqarr;
	double _vectime;
	double _deqtime;
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
	template <typename T> T MergeSort(T& container);
	template <typename T> T merge(T &left, T &right);

	void PrintAll();
	template <typename T> void PrintContainer(T& container);
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
