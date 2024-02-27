#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade)
{
	std::cout << "Form default constructor is called!" << std::endl;
	try
	{
		if (signGrade < 1)
			throw (1);
		if (signGrade > 150)
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
			std::cout << "ExecGrade exception" << std::endl;
			if (error == 3)
			{
				this->GradeTooHighException();
				return ;
			}
			if (error == 5)
			{
				this->GradeTooLowException();
				return ;
			}			
		}
	}
	this->_name = name;
	this->_signGrade = signGrade;
	this->_execGrade = execGrade;
	this->_signed = false;
}

Form::Form(const Form &in)
{
	std::cout << "Form copy constructor is called!" << std::endl;
	*this = in;
}

Form& Form::operator=(const Form &in)
{
	if (this == &in)
		return (*this);
	this->_name = in._name;
	this->_signGrade = in._signGrade;
	this->_execGrade = in._execGrade;
	this->_signed = in._signed;
	return (*this);
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

void	Form::beSigned(Bureaucrat &in)
{
	try
	{
		if (this->_signGrade < in.getGrade())
			throw (1);
	}
	catch(int error)
	{
		if (error == 1)
		{
			std::cout << "beSigned exception!" << std::endl;
			this->GradeTooLowException();
			return ;
		}
	}
	this->_signed = true;
}

std::string	Form::getName()
{
	return (this->_name);
}

int	Form::getGrade()
{
	return (this->_signGrade);
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
	out << "Form name: " << in.getName() << ", is the form signed: " << in.getSigned() << ", minimal grade to sign is: " << in.getGrade() << ", minimal grade to execute is: " << in.getExecGrade();
	return (out);
}