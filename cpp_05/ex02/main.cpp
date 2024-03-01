#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	
	// std::cout << std::endl;
	// std::cout << "---------AFormS---------" << std::endl;

	// std::cout << std::endl;
	// AForm ContractAH("AH_medewerker", 50, 20);
	// AForm contractDIRK("Dirk_medewerker", 140, 5);
	// AForm contractLIDL("Lidl_medewerker", 157, 3);
	// AForm contractJUMBO("Jumbo_medewerker", 143, -420);
	// std::cout << std::endl;
	// std::cout << ContractAH << std::endl;
	// std::cout << contractDIRK << std::endl;
	
	// std::cout << std::endl;
	// ContractAH.beSigned(c);
	// ContractAH.beSigned(b);
	// ContractAH.beSigned(a);

	// std::cout << std::endl;
	// std::cout << ContractAH << std::endl;

	// std::cout << std::endl;
	// c.signAForm(ContractAH);
	// b.signAForm(ContractAH);
	// a.signAForm(ContractAH);

	// std::cout << std::endl;
	// c.signAForm(contractDIRK);

	// std::cout << std::endl;
	// contractDIRK.beSigned(c);
	// contractDIRK.beSigned(b);

	// std::cout << std::endl;
	// c.signAForm(contractDIRK);
	// b.signAForm(contractDIRK);

	// std::cout << std::endl;
	// std::cout << contractDIRK << std::endl;

	std::cout << "-------------FORMS-----------" << std::endl;
	std::cout << std::endl;

	PresidentialPardonForm PPF("Anrold");
	RobotomyRequestForm RRF("Richard");
	ShrubberyCreationForm SCF("Apartment");
	Bureaucrat bruh("son", 149);
	Bureaucrat lord("PRAISEME", 2);

	std::cout << std::endl;
	PPF.execute(bruh);
	RRF.execute(bruh);
	SCF.execute(bruh);

	std::cout << std::endl;
	PPF.beSigned(bruh);
	PPF.beSigned(lord);
	RRF.beSigned(lord);
	SCF.beSigned(lord);

	std::cout << std::endl;	
	PPF.execute(bruh);
	RRF.execute(bruh);
	SCF.execute(bruh);

	std::cout << std::endl;
	PPF.execute(lord);
	RRF.execute(lord);
	SCF.execute(lord);
	std::cout << std::endl;
}