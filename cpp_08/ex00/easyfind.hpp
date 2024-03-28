#pragma once

#include <iostream>
#include <iterator>
#include <vector>

class IntNotFoundException : public std::exception
{
	const char *what() const throw()
	{
		return ("The interger value you are trying to find in the container isn't inside the container!!");
	}
};


template <typename T> void easyfind(T container, int value)
{
	std::vector<int>::iterator index;
	
	for (index = container.begin(); index < container.end(); index++)
	{
		if (value == *index)
		{
			std::cout << "Int has been found" << std::endl;
			return ;
		}
	}
	throw (IntNotFoundException());
}