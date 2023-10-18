#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	func	funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int index = 0;
	while (level[index])
	{
		level[index] = tolower(level[index]);
		index++;
	}
	index = 0;
	while (index < 4)
	{
		if (levels[index].compare(level) == 0)
			break ;
		index++;
	}
	if (index == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}	
    switch (index) { 
    case 0: 
		std::cout << "[DEBUG]" << std::endl;
		(this->*funcs[index])();
		index += 1;
    case 1: 
		std::cout << "[INFO]" << std::endl;
		(this->*funcs[index])();
		index += 1;
    case 2: 
		std::cout << "[WARNING]" << std::endl;
		(this->*funcs[index])();
		index += 1;
    case 3:
		std::cout << "[ERROR]" << std::endl;
		(this->*funcs[index])();
    }
	return ;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}