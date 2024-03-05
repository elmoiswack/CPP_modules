#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &in);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &in);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};