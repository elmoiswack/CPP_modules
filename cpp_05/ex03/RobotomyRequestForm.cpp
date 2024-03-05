#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor is called and types are set!" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &in) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = in;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &in)
{
	if (this == &in)
		return (*this);
	this->_target = in._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor is called!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
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
		std::cout << "RobotomyRequestForm exception caught!" << std::endl;
		std::cerr << e.what() << '\n';
		return ;
	}
	if (this->getSigned() == true && executor.getGrade() < this->getExecGrade())
	{
		std::cout << "DRRRRRRRRRRRIIIIIIIIIIIILLLLLLLLLLLLLLLL!!!!!!!! (lots of dill noise)." << std::endl;
		srand(time(NULL));
		int i = std::rand()%100;
		if (i % 2 == 0)
			std::cout << this->_target << " has been robotomized, robotomisation was succesfull!" << std::endl;
		else
			std::cout << this->_target << " has NOT been robotomized, robotomisation was unsuccesfull!" << std::endl;
	}
}