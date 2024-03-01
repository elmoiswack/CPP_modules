#pragma once

#include <iostream>

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

	void	incrementGrade();
	void	decrementGrade();

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

	const std::string	getName();
	int		getGrade();
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &in);