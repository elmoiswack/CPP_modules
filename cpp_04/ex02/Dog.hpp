#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* dogBrain;
public:
	Dog();
	Dog(const Dog &in);
	Dog& operator=(const Dog &in);
	~Dog();
	void	makeSound() const;
	const std::string getType() const;
};


#endif