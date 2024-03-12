#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor is called and types are set!" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &in) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = in;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &in)
{
	if (this == &in)
		return (*this);
	this->_target = in._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor is called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (this->getSigned() != true)
			throw (AForm::FormSignedFalseException());
		if (executor.getGrade() > this->getExecGrade())
			throw (AForm::FormBureauExecException());
	}
	catch(const std::exception& e)
	{
		std::cout << "PresidentialPardonForm exception caught!" << std::endl;
		std::cerr << e.what() << '\n';
		return ;
	}
	if (this->getSigned() == true && executor.getGrade() < this->getExecGrade())
	{
		std::cout << this->_target << " is pardoned by Zaphod Beeblebrox. The president is very happy!" << std::endl;
	}
}