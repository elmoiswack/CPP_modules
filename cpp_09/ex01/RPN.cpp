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

	for (index = 0; input[index]; index++)
	{
		if ((std::isdigit(input[index]) == 0) && (this->IsPlusMinDeviMulti(input[index]) == false) && (input[index] != ' '))
			throw (InvalidCharInStrException());	
		if (input[index] != ' ')
		{
			if (input[index + 1] != '\0' && input[index + 1] != ' ')
				throw (InvalidCharInStrException());
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

void RPN::SingleOperation(std::queue<int>& container, char which)
{
	int temp = container.front();
	container.pop();
	if (which == '+')
	{
		unsigned int result = temp + container.front();
		container.pop();
		container.push(result);
	}
	else if (which == '-')
	{
		unsigned int result = temp - container.front();
		container.pop();
		container.push(result);
	}
	else if (which == '/')
	{
		unsigned int result = temp / container.front();
		container.pop();
		container.push(result);
	}
	else if (which == '*')
	{ 
		unsigned int result = temp * container.front();
		container.pop();
		container.push(result);
	}
}

int RPN::MultipleOperation(std::queue<int>& container, std::string input, int index)
{
	unsigned int result;

	result = container.front();
	container.pop();

	while (container.size() > 1)
	{
		SingleOperation(container, input[index]);
		if (((index + 2) < (int)input.size()) && (this->IsPlusMinDeviMulti(input[index + 2]) == true))
			index += 2;
		else
			break ;
	}
	container.push(result);
	SingleOperation(container, input[index]);
	return (index);
}

void RPN::CalculateNumb(char *input)
{
	std::string InputStr(input);
	std::queue<int> container;

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
	std::cout << container.front() << std::endl;
	container.pop();
}

const char* RPN::InvalidEndStringException::what() const throw()
{
	return ("ERROR: the input str must end with an '+ - / *'!");
}

const char* RPN::InvalidStrException::what() const throw()
{
	return ("ERROR: invalid input!");
}

const char* RPN::InvalidCharInStrException::what() const throw()
{
	return ("ERROR: there is a character that shouldn't be in the input str!");
}