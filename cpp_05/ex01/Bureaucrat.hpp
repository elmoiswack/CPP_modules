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
	
	void	GradeTooHighException();
	void	GradeTooLowException();
	void	incrementGrade();
	void	decrementGrade();

	const std::string	getName();
	int		getGrade();
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &in);