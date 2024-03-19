#include "Serializer.hpp"

int main(void)
{
	Data		*ptr = new Data;
	Data		*copy;
	uintptr_t 	numb;

	ptr->lmao = "you can modify this str if you like!";

	numb = Serializer::serialize(ptr);
	copy = Serializer::deserialize(numb);

	if (copy == ptr)
	{
		std::cout << "Good!" << std::endl;
		std::cout << copy->lmao << std::endl;
	}
	else
		std::cout << "Very bad!" << std::endl;

	delete ptr;
	return (0);	
}