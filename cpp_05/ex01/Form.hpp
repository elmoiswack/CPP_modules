#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool		_signed;
	int			_signGrade;
	int			_execGrade;
public:
	Form(std::string name, int signGrade, int execGrade);
	~Form();
	Form(Form &in);
	Form& operator=(const Form &in);

	const std::string	getName();
	int			getGrade();
	int			getExecGrade();
	bool		getSigned();

	void	beSigned(Bureaucrat &in);

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw()
		{
			return ("The FORM grade you are trying to is too high!");
		}
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw()
		{
			return ("The FORM grade you are trying to set is too low or the Bureaucrat grade is too low to sign!");
		}
	};

};

std::ostream& operator<<(std::ostream &out, Form &in);