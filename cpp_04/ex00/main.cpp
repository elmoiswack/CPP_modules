#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete j;
	delete i;
	delete meta;

	std::cout << std::endl;
	const WrongAnimal* wanim = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();

	std::cout << std::endl;
	std::cout << wanim->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;

	std::cout << std::endl;
	wanim->makeSound();
	wcat->makeSound();

	std::cout << std::endl;
	delete wanim;
	delete wcat;
	
	return 0;	
}