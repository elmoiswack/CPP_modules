#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &in);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &in);
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};