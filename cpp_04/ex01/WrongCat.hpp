#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &in);
	~WrongCat();
	void	makeSound() const;
	WrongCat& operator=(const WrongCat &in);
	std::string getType() const;
};


#endif