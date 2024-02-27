#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string _name;
	bool		_signed;
	int			_signGrade;
	int			_execGrade;
public:
	Form(std::string name, int signGrade, int execGrade);
	~Form();
	Form(const Form &in);
	Form& operator=(const Form &in);
	void	GradeTooHighException();
	void	GradeTooLowException();

	std::string	getName();
	int			getGrade();
	int			getExecGrade();
	bool		getSigned();

	void	beSigned(Bureaucrat &in);
};

std::ostream& operator<<(std::ostream &out, Form &in);