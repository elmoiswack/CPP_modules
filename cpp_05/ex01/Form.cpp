#include "Form.hpp"

Form::Form(std::string name, int grade, int execGrade)
{
	std::cout << "Form default constructor is called!" << std::endl;
	try
	{
		if (grade < 1)
			throw (1);
		if (grade > 150)
			throw (2);
		if (execGrade < 1)
			throw (3);
		if (execGrade > 150)
			throw (4);
	}
	catch(int error)
	{
		if (error == 1 || error == 2)
		{
			std::cout << "Grade exception" << std::endl;
			if (error == 1)
			{
				this->GradeTooHighException();
				return ;
			}
			if (error == 2)
			{
				this->GradeTooLowException();
				return ;
			}
		}
		else if (error == 3 || error == 4)
		{
			std::cout << "execGrade "
		}
	}
	this->_name = name;
	this->_grade = grade;
	this->_execGrade = execGrade;
	this->_signed = false;
}

Form::~Form()
{
	std::cout << "Form default deconstructor is called!" << std::endl;
}

void	Form::GradeTooHighException()
{
	std::cout << "The grade isn't valid, it's too high!" << std::endl;
}

void	Form::GradeTooLowException()
{
	std::cout << "The grade isn't valid, it's too low!" << std::endl;
}

void	Form::beSigned(const Bureaucrat &in)
{

}

std::string	Form::getName()
{
	return (this->_name);
}

int	Form::getGrade()
{
	return (this->_grade);
}

int	Form::getExecGrade()
{
	return (this->_execGrade);
}

bool	Form::getSigned()
{
	return (this->_signed);
}

std::ostream& operator<<(std::ostream &out, Form &in)
{

}