#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "Default constructor is called!" << std::endl;
	this->_vectime = 0;
	this->_deqtime = 0;
}

PmergeMe::PmergeMe(PmergeMe &in)
{
	std::cout << "Copy constructor is called!" << std::endl;
	*this = in;
}

PmergeMe& PmergeMe::operator=(PmergeMe &in)
{
	if (this == &in)
		return (*this);
	this->_vectime = in._vectime;
	this->_deqtime = in._deqtime;
	if (in._vecarr.size() > 0)
	{
		std::vector<int>::iterator init = in._vecarr.begin();
		for (; init != in._vecarr.end(); init++)
		{
			this->_vecarr.insert(*init);
		}
	}
	if (in._deqarr.size() > 0)
	{
		std::deque<int>::iterator initdeq = in._deqarr.begin();
		for (; initdeq != in._deqarr.end(); initdeq++)
		{
			this->_deqarr.insert(*initdeq);
		}
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "Default deconstrcutor is called!" << std::endl;
}