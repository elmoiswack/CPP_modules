#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat a("Albert", 1);
	Bureaucrat b("Brad", 132);
	Bureaucrat c("Chad", 150);
	std::cout << std::endl;
	Bureaucrat d("Derek", -1);
	Bureaucrat e("Eric", 165);

	std::cout << std::endl;
	a.incrementGrade();
	std::cout << a << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;

	std::cout << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
	b.decrementGrade();
	std::cout << b << std::endl;

	std::cout << std::endl;
	c.decrementGrade();
	std::cout << c << std::endl;
	c.incrementGrade();
	std::cout << c << std::endl;
	
	std::cout << std::endl;
}