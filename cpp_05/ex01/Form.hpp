#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string _name;
	bool		_signed;
	int			_grade;
	int			_execGrade;
public:
	Form(std::string name, int grade, int execGrade);
	~Form();

	void	GradeTooHighException();
	void	GradeTooLowException();

	std::string	getName();
	int			getGrade();
	int			getExecGrade();
	bool		getSigned();

	void	beSigned(const Bureaucrat &in);
};

std::ostream& operator<<(std::ostream &out, Form &in);