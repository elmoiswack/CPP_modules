#pragma once

#include <iostream>

struct Data {
	std::string lmao; 
};

class Serializer
{
private:
	Serializer();
	Serializer(Serializer &in);
	Serializer &operator=(Serializer &in);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

