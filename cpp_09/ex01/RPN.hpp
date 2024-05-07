#pragma once

#include <iostream>
#include <stack>

class RPN
{
private:

public:
	RPN();
	RPN(RPN& in);
	RPN& operator=(RPN& in);
	~RPN();

	bool IsPlusMinDeviMulti(char c);

	int MultipleOperation(std::stack<int>& container, std::string input, int index);
	void SingleOperation(std::stack<int>& container, char which);
	void SingleOperationMult(std::stack<int>& container, char which);
	void CalculateNumb(char *input);
	void InputParser(std::string input);

	class DivZeroException : public std::exception
	{
		const char *what() const throw();
	};

	class InvalidBeginStringException : public std::exception
	{
		const char *what() const throw();
	};

	class TooManySpacesStringException : public std::exception
	{
		const char *what() const throw();
	};

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

	class TooManyCharException : public std::exception
	{
		const char *what() const throw();
	};
};

