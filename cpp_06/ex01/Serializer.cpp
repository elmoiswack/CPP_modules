#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor is called!" << std::endl;
}

Serializer::Serializer(Serializer &in)
{
	std::cout << "Copy constructor is called!" << std::endl;
	*this = in;
}

Serializer& Serializer::operator=(Serializer &in)
{
	std::cout << "Operator overload '=' is called!" << std::endl;
	return (in);
}

Serializer::~Serializer()
{
	std::cout << "Default deconstructor is called!" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}