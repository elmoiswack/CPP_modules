#pragma once

#include <iostream>
#include <queue>

class RPN
{
private:

public:
	RPN();
	RPN(RPN& in);
	RPN& operator=(RPN& in);
	~RPN();

	bool IsPlusMinDeviMulti(char c);

	int MultipleOperation(std::queue<int>& container, std::string input, int index);
	void SingleOperation(std::queue<int>& container, char which);
	void SingleOperationLast(std::queue<int>& container, char which);
	void CalculateNumb(char *input);
	void InputParser(std::string input);


	class InvalidCharInStrException : public std::exception
	{
		const char *what() const throw();
	};

	class InvalidStrException : public std::exception
	{
		const char *what() const throw();
	};

	class InvalidEndStringException : public std::exception
	{
		const char *what() const throw();
	};
};

