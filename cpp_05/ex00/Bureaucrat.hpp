#ifndef BUREAUCRAT_HPP
# define BUREACRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int	grade;
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	void	GradeTooHighException();
	void	GradeTooLowException();
	void	getName();
	void	getGrade();
};


#endif