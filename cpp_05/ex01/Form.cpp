#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name)
{
	std::cout << "Form default constructor is called!" << std::endl;
	try
	{
		if (signGrade < 1)
			throw (GradeTooHighException());
		if (signGrade > 150)
			throw (GradeTooLowException());
		if (execGrade < 1)
			throw (GradeTooHighException());
		if (execGrade > 150)
			throw (GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cout << "Form constructor exception caught with " << name << " Form!" << std::endl;
		std::cerr << e.what() << std::endl;
		return ;
	}

	this->_signGrade = signGrade;
	this->_execGrade = execGrade;
	this->_signed = false;
}

Form::Form(Form &in) : _name(in.getName())
{
	std::cout << "Form copy constructor is called!" << std::endl;
	*this = in;
}

Form& Form::operator=(const Form &in)
{
	if (this == &in)
		return (*this);
	this->_signGrade = in._signGrade;
	this->_execGrade = in._execGrade;
	this->_signed = in._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form default deconstructor is called!" << std::endl;
}

void	Form::beSigned(Bureaucrat &in)
{
	try
	{
		if (this->_signGrade < in.getGrade())
			throw (GradeTooLowException());		
	}
	catch(const std::exception& e)
	{
		std::cout << "Form beSigned exception caught with " << this->_name << " AForm!" << std::endl;
		std::cerr << e.what() << '\n';
		in.signForm(*this);
		return ;
	}
	std::cout << "The " << this->_name << " form has been signed by " << in.getName() << std::endl;
	this->_signed = true;
	in.signForm(*this);
}

const std::string	Form::getName()
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
	out << "Form name: " << in.getName() << ", is the form signed: ";
	if (in.getSigned() == false)
	{
		out << "false";
	}
	else if (in.getSigned() == true)
	{
		out << "true";
	}
	out << ", minimal grade to sign is: " << in.getGrade() << ", minimal grade to execute is: " << in.getExecGrade();
	return (out);
}