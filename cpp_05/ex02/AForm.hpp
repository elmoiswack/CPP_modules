#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool		_signed;
	int			_signGrade;
	int			_execGrade;
public:
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(AForm &in);
	AForm& operator=(const AForm &in);

	const std::string	getName() const;
	int			getGrade() const;
	int			getExecGrade() const;
	bool		getSigned() const;

	void	beSigned(Bureaucrat &in);

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw()
		{
			return ("The AForm grade you are trying to is too high!");
		}
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw()
		{
			return ("The AForm grade you are trying to set is too low or the Bureaucrat grade is too low to sign!");
		}
	};

	class FormSignedFalseException : public std::exception
	{
		const char *what() const throw()
		{
			return ("The Form you are trying to execute hasn't been signed yet!");
		}		
	};

	class FormBureauExecException : public std::exception
	{
		const char *what() const throw()
		{
			return ("The Bureaucrats grade it too low to execute the form, ask your superior to execute the form!");
		}	
	};


	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &out, AForm &in);