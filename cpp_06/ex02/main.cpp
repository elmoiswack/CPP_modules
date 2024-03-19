#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int	randomNumb;
	Base *ptr;
	srand(time(0));
	randomNumb = rand() % 100;

	if (randomNumb < 33)
	{
		std::cout << "Generated A!" << std::endl;
		ptr = new A;
	}
	else if (randomNumb >= 33 && randomNumb < 66)
	{
		std::cout << "Generated B!" << std::endl;
		ptr = new B;
	}
	else
	{
		std::cout << "Generated C!" << std::endl;
		ptr = new C;
	}
	return (ptr);
}

void identify(Base* p)
{
	std::cout << "Pointers are cool!" << std::endl;
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Identified A class!" << std::endl;
		return ;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Identified B class!" << std::endl;
		return ;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Identified C class!" << std::endl;
		return ;
	}
	std::cout << "The base * is neither A, B or C. What happend??????????" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Pointers are dumb!" << std::endl;
	if (dynamic_cast<A *>(&p))
	{
		std::cout << "Identified A class!" << std::endl;
		return ;
	}
	else if (dynamic_cast<B *>(&p))
	{
		std::cout << "Identified B class!" << std::endl;
		return ;
	}
	else if (dynamic_cast<C *>(&p))
	{
		std::cout << "Identified C class!" << std::endl;
		return ;
	}
	std::cout << "The base * is neither A, B or C. What happend??????????" << std::endl;
}

int	main(void)
{
	Base *ptr;
	ptr = generate();
	std::cout << std::endl;
	identify(ptr);
	std::cout << std::endl;
	identify(*ptr);
	std::cout << std::endl;
	identify(NULL);
	std::cout << std::endl;
	delete ptr;
	return 0;
}