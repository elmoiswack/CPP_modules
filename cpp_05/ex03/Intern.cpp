#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor is called!" << std::endl;
}

Intern::Intern(Intern &in)
{
	std::cout << "Intern copy constructor is called!" << std::endl;
	*this = in;
}

Intern& Intern::operator=(Intern &in)
{
	std::cout << "Intern operator overload '=' is called!" << std::endl;
	if (this == &in)
		return (*this);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor is called!" << std::endl;
}

AForm* Intern::makeForm(std::string nameForm, std::string targetForm)
{
	std::cout << "Intern is making a new form!" << std::endl;
	const std::string arr[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int	index = 0;
	while (index < 3)
	{
		if (arr[index] == nameForm)
			break ;
		index++;
	}
	try
	{
		switch (index)
		{
			case 0:
			{
				AForm *newForm = new RobotomyRequestForm(targetForm);
				return (newForm);
			}
			case 1:
			{
				AForm *newForm = new PresidentialPardonForm(targetForm);
				return (newForm);
			}
			case 2:
			{
				AForm *newForm = new ShrubberyCreationForm(targetForm);
				return (newForm);
			}
			default:
				throw (unknownFormException());
				break ;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}