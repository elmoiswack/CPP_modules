#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* catBrain;
public:
	Cat();
	~Cat();
	void	makeSound() const;
	std::string getType() const;
};

#endif