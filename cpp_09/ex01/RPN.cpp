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
	}
}

void RPN::SingleOperation(std::queue<int>& container, char which)
{
	if (which == '+')
	{
		unsigned int result = container.front() + container.back();
		container.pop();
		container.pop();
		container.push(result);
	}
	else if (which == '-')
	{
		unsigned int result = container.front() - container.back();
		container.pop();
		container.pop();
		container.push(result);
	}
	else if (which == '/')
	{
		unsigned int result = container.front() / container.back();
		container.pop();
		container.pop();
		container.push(result);
	}
	else if (which == '*')
	{ 
		unsigned int result = container.front() * container.back();
		container.pop();
		container.pop();
		container.push(result);
	}
}

void RPN::MultipleOperation(std::queue<int>& container, std::string input, int index)
{

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
				this->MultipleOperation(container, InputStr, index);
			else
				this->SingleOperation(container, InputStr[index]);
		}
	}
	std::cout << container.front() << std::endl;
}

const char* RPN::InvalidEndStringException::what() const throw()
{
	return ("ERROR: the input str must end with an '+ - / *'!");
}

const char* RPN::InvalidCharInStrException::what() const throw()
{
	return ("ERROR: there is a character that shouldn't be in the input str!");
}