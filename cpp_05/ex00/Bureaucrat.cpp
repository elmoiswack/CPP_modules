#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	std::cout << "Bureaucrat default constructor is called!" << std::endl;
	try
	{
		if (grade < 1)
			throw (1);
		if (grade > 150)
			throw (2);
	}
	catch (int which)
	{
		std::cout << "Exception is caught!" << std::endl;
		if (which == 1)
		{
			this->GradeTooHighException();
			return ;
		}
		else if (which == 2)
		{
			this->GradeTooLowException();
			return ;
		}
	}
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& in)
{
	std::cout << "Bureaucrat copy constructor is called!" << std::endl;
	*this = in;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &in)
{
	if (this == &in)
		return (*this);
	this->_name = in._name;
	this->_grade = in._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default deconstructor is called!" << std::endl;
}

void	Bureaucrat::GradeTooHighException()
{
	std::cout << "The grade you are trying to set isn't in scope! The grade is too high!" << std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	std::cout << "The grade you are trying to set isn't in scope! The grade is too low!" << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade == 150)
			throw (1);
	}
	catch (int error)
	{
		std::cout << "Exception is caught!" << std::endl;
		if (error == 1)
			this->GradeTooLowException();
		return ;
	}
	std::cout << this->getName() << " grade is decremented from: " << this->getGrade();
	this->_grade += 1;
	std::cout << " to: " << this->getGrade() << std::endl;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade == 1)
			throw (1);
	}
	catch (int error)
	{
		std::cout << "Exception is caught!" << std::endl;
		if (error == 1)
			this->GradeTooHighException();
		return ;
	}	
	std::cout << this->getName() << " grade is incremented from: " << this->getGrade();
	this->_grade -= 1;
	std::cout << " to: " << this->getGrade() << std::endl;
}


int	Bureaucrat::getGrade()
{
	return (this->_grade);
}

const std::string Bureaucrat::getName()
{
	return (this->_name);
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &in)
{
	out << in.getName() << ", bureaucrat grade " << in.getGrade();
	return (out);
}