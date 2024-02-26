#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &in);
	virtual ~Animal();
	virtual void	makeSound() const = 0;
	Animal& operator=(const Animal &in);
	std::string getType() const;
};

#endif