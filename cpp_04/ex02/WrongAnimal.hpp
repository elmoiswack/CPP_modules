#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &in);
	virtual ~WrongAnimal();
	void	makeSound() const;
	WrongAnimal& operator=(const WrongAnimal &in);
	std::string getType() const;
};


#endif
