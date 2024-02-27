#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	
	Form Contract("AH", 50, 20);
	std::cout << std::endl;
	std::cout << Contract << std::endl;
	std::cout << std::endl;
	Contract.beSigned(c);
	Contract.beSigned(b);
	Contract.beSigned(a);
	std::cout << std::endl;
	c.signForm(Contract);
	b.signForm(Contract);
	a.signForm(Contract);
	
	std::cout << std::endl;
}