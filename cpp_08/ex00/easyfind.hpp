#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

class IntNotFoundException : public std::exception
{
	const char *what() const throw();
};


template <typename T> void easyfind(T container, int value)
{
	std::vector<int>::iterator index;

	index = std::find(container.begin(), container.end(), value);
	if (index != container.end())
	{
		std::cout << "Int has been found" << std::endl;
	 		return ;		
	}
	throw (IntNotFoundException());
}
