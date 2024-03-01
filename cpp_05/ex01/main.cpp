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
	
	std::cout << std::endl;
	std::cout << "---------FORMS---------" << std::endl;

	std::cout << std::endl;
	Form ContractAH("AH_medewerker", 50, 20);
	Form contractDIRK("Dirk_medewerker", 140, 5);
	Form contractLIDL("Lidl_medewerker", 157, 3);
	Form contractJUMBO("Jumbo_medewerker", 143, -420);
	std::cout << std::endl;
	std::cout << ContractAH << std::endl;
	std::cout << contractDIRK << std::endl;
	
	std::cout << std::endl;
	ContractAH.beSigned(c);
	ContractAH.beSigned(b);
	ContractAH.beSigned(a);

	std::cout << std::endl;
	std::cout << ContractAH << std::endl;

	std::cout << std::endl;
	c.signForm(ContractAH);
	b.signForm(ContractAH);
	a.signForm(ContractAH);

	std::cout << std::endl;
	c.signForm(contractDIRK);

	std::cout << std::endl;
	contractDIRK.beSigned(c);
	contractDIRK.beSigned(b);

	std::cout << std::endl;
	c.signForm(contractDIRK);
	b.signForm(contractDIRK);

	std::cout << std::endl;
	std::cout << contractDIRK << std::endl;

	std::cout << std::endl;
}