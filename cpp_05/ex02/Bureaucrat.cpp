#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
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
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& in) : _name(in.getName())
{
	std::cout << "Bureaucrat copy constructor is called!" << std::endl;
	*this = in;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &in)
{
	if (this == &in)
		return (*this);
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


int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::signAForm(AForm &in)
{
	if (in.getSigned() == true)
	{
		std::cout << this->_name << " signed " << in.getName() << std::endl;
	}
	else
		std::cout << "The " << in.getName() << " AForm hasn't been authorized by a superior!" << std::endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &in)
{
	out << in.getName() << ", bureaucrat grade " << in.getGrade();
	return (out);
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		if (form.getSigned() != true)
			throw (AForm::FormSignedFalseException());
		if (this->getGrade() > form.getExecGrade())
			throw (AForm::FormBureauExecException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}