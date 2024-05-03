#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor is called!" << std::endl;
}

RPN::RPN(RPN& in)
{
	std::cout << "Copy constructor is called!" << std::endl;
	*this = in;
}

RPN& RPN::operator=(RPN& in)
{
	std::cout << "Operator overload '=' is called!" << std::endl;
	if (this == &in)
		return (*this);
	return (*this);
}

RPN::~RPN()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

bool RPN::IsPlusMinDeviMulti(char c)
{
	if (c == '+')
		return (true);
	if (c == '-')
		return (true);
	if (c == '/')
		return (true);
	if (c == '*')
		return (true);
	return (false);
}

void RPN::InputParser(std::string input)
{
	int index;
	int numb_count = 0;
	int operator_count = 0;

	if (input.size() == 1)
	{
		if (std::isdigit(input[0]) > 0)
			return ;
		else
			throw (InvalidStrException());
	}
	for (index = 0; input[index]; index++)
	{
		if (index == 0 || index == 2)
		{
			if (std::isdigit(input[index]) == 0)
				throw (InvalidBeginStringException());
		}
		if ((std::isdigit(input[index]) == 0) && (this->IsPlusMinDeviMulti(input[index]) == false) && (input[index] != ' '))
			throw (InvalidCharInStrException());	
		if (input[index] == ' ')
		{
			if (index + 1 < (int)input.size() && input[index + 1] == ' ')
				throw (TooManySpacesStringException());
		}
		if (input[index] != ' ')
		{
			if (input[index + 1] != '\0' && input[index + 1] != ' ')
				throw (TooManyCharException());
		}
		if (this->IsPlusMinDeviMulti(input[index]) == false && input[index + 1] == '\0')
			throw (InvalidEndStringException());
		if (std::isdigit(input[index]) != 0)
			numb_count += 1;
		if (this->IsPlusMinDeviMulti(input[index]) == true)
			operator_count += 1;
	}
	if ((numb_count - 1) != operator_count)
		throw (InvalidStrException());
}

void RPN::SingleOperation(std::stack<int>& container, char which)
{
	int temp = container.top();
	container.pop();
	if (which == '+')
	{
		unsigned int result = container.top() + temp;
		container.pop();
		container.push(result);
	}
	else if (which == '-')
	{
		unsigned int result = container.top() - temp;
		container.pop();
		container.push(result);
	}
	else if (which == '/')
	{
		unsigned int result = container.top() / temp;
		container.pop();
		container.push(result);
	}
	else if (which == '*')
	{ 
		unsigned int result = container.top() * temp;
		container.pop();
		container.push(result);
	}
}

void RPN::SingleOperationMult(std::stack<int>& container, char which)
{
	int back = container.top();
	container.pop();
	int front = container.top();
	container.pop();
	if (which == '+')
	{
		unsigned int result = front + back;
		container.push(result);
	}
	else if (which == '-')
	{
		unsigned int result = front - back;
		container.push(result);
	}
	else if (which == '/')
	{
		unsigned int result = front / back;
		container.push(result);
	}
	else if (which == '*')
	{ 
		unsigned int result = front * back;
		container.push(result);
	}
}

int RPN::MultipleOperation(std::stack<int>& container, std::string input, int index)
{
	while (container.size() > 1)
	{
		SingleOperationMult(container, input[index]);
		if (((index + 2) < (int)input.size()) && (this->IsPlusMinDeviMulti(input[index + 2]) == true))
			index += 2;
		else
			break ;
	}
	return (index);
}

void RPN::CalculateNumb(char *input)
{
	std::string InputStr(input);
	std::stack<int> container;

	this->InputParser(InputStr);
	for (int index = 0; InputStr[index]; index++)
	{
		if (InputStr[index] == ' ')
			index++;
		if (std::isdigit(InputStr[index]) > 0)
			container.push(InputStr[index] - '0');
		if (this->IsPlusMinDeviMulti(InputStr[index]) == true)
		{
			if (((index + 2) < (int)InputStr.size()) && (this->IsPlusMinDeviMulti(InputStr[index + 2]) == true))
				index = this->MultipleOperation(container, InputStr, index);
			else
				this->SingleOperation(container, InputStr[index]);
		}
	}
	std::cout << container.top() << std::endl;
	container.pop();
}

const char* RPN::TooManySpacesStringException::what() const throw()
{
	return ("check if the input str only has 1 space between the numbers and operators!");
}

const char* RPN::InvalidBeginStringException::what() const throw()
{
	return ("the input str must begin with 2 numbers!");
}

const char* RPN::InvalidEndStringException::what() const throw()
{
	return ("the input str must end with an '+ - / *'!");
}

const char* RPN::InvalidStrException::what() const throw()
{
	return ("invalid input!");
}

const char* RPN::InvalidCharInStrException::what() const throw()
{
	return ("there is a character that shouldn't be in the input str!");
}

const char* RPN::TooManyCharException::what() const throw()
{
	return ("a single char should be followed by a ' ' not another char!");
}

//+ 1 + 1 2 2 +
//1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /
//1 2 3 4 * + -