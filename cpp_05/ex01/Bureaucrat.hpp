#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string _name;
	int	_grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat &in);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat &in);

	const std::string	getName();
	int		getGrade();

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &in);

class GradeTooHighException : public std::exception
{
public:
	const char *what() const throw()
	{
		return ("The grade you are trying to set isn't in scope! The grade is too high!");
	}
};

class GradeTooLowException : public std::exception
{
public:
	const char *what() const throw()
	{
		return ("The grade you are trying to set isn't in scope! The grade is too low!");
	}
};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &in);