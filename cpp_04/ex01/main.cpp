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
	
	std::cout << std::endl;
	std::cout << "Copy constructors" << std::endl;

	const Animal* d = new Cat();
	const Animal* copy = new Cat(*((Cat *)d));
	std::cout << std::endl;
	delete d;
	delete copy;
	std::cout << std::endl;

	Animal* arr[10];
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "index = " << i << std::endl;
		if (i % 2 == 0)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "All animals have been allocated, time to delete them!!" << std::endl;

	std::cout << std::endl;
	for (int a = 0; a < 10; a++)
	{
		std::cout << "index = " << a << std::endl;
		delete arr[a];
		std::cout << std::endl;
	}
	return 0;	
}