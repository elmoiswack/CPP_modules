#pragma once

#include "iostream"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &in);
	Intern& operator=(Intern &in);
	~Intern();

	class unknownFormException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("The form you are trying to create doens't exist, the intern doens't know what to do!");
		}		
	};

	AForm *makeForm(std::string nameForm, std::string targetForm);
};
