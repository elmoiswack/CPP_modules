#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	std::cout << "Bureaucrat default constructor is called!" << std::endl;
	try
	{
		if (grade < 1)
			throw (GradeTooHighException());
		if (grade > 150)
			throw (GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat constructor exception caught!" << std::endl;
		std::cerr << e.what() << std::endl;
		return ;
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


void	Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade == 150)
			throw (GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cout << "DecrementGrade exception caught!" << std::endl;
		std::cerr << e.what() << std::endl;
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
			throw (GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cout << "IncrementGrade exception caught!" << std::endl;
		std::cerr << e.what() << std::endl;
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

void	Bureaucrat::signForm(Form &in)
{
	if (in.getSigned() == true)
	{
		std::cout << this->_name << " signed " << in.getName() << std::endl;
	}
	else
		std::cout << "The " << in.getName() << " form hasn't been authorized by a superior!" << std::endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &in)
{
	out << in.getName() << ", bureaucrat grade " << in.getGrade();
	return (out);
}