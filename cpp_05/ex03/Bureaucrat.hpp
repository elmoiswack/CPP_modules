#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int	_grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat &in);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat &in);

	const std::string	getName() const;
	int getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signAForm(AForm &in);

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

	void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &in);