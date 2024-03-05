#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &in);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &in);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};

