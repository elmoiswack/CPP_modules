#include "AForm.hpp"

AForm::AForm()
{
	std::cout << "AForm default constructor is called!" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name)
{
	std::cout << "AForm default constructor is called and vars have been set!" << std::endl;
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
		std::cout << "AForm constructor exception caught with " << name << " AForm!" << std::endl;
		std::cerr << e.what() << std::endl;
		return ;
	}

	this->_signGrade = signGrade;
	this->_execGrade = execGrade;
	this->_signed = false;
}

AForm::AForm(AForm &in) : _name(in.getName())
{
	std::cout << "AForm copy constructor is called!" << std::endl;
	*this = in;
}

AForm& AForm::operator=(const AForm &in)
{
	if (this == &in)
		return (*this);
	this->_signGrade = in._signGrade;
	this->_execGrade = in._execGrade;
	this->_signed = in._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm default deconstructor is called!" << std::endl;
}

void	AForm::beSigned(Bureaucrat &in)
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
		return ;
	}
	std::cout << "The " << this->_name << " AForm has been signed by " << in.getName() << std::endl;
	this->_signed = true;
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

std::ostream& operator<<(std::ostream &out, AForm &in)
{
	out << "AForm name: " << in.getName() << ", is the AForm signed: ";
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