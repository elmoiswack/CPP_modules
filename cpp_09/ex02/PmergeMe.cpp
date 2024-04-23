#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe()
{
	std::cout << "Default constructor is called!" << std::endl;
	this->_elements = 0;
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
	this->_elements = in._elements;
	if (in._vecarr.size() > 0)
	{
		std::vector<int>::iterator init = in._vecarr.begin();
		for (; init != in._vecarr.end(); init++)
		{
			this->_vecarr.insert(init, *init);
		}
	}
	if (in._deqarr.size() > 0)
	{
		std::deque<int>::iterator initdeq = in._deqarr.begin();
		for (; initdeq != in._deqarr.end(); initdeq++)
		{
			this->_deqarr.insert(initdeq, *initdeq);
		}
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "Default deconstrcutor is called!" << std::endl;
}

void PmergeMe::AddNumberToBoth(char *numb)
{
	int number;

	number = std::stoi(numb);
	this->_vecarr.push_back(number);
	this->_deqarr.push_back(number);
	this->_elements += 1;
}

template <typename T>
void PmergeMe::PrintContainer(T container)
{
	int count = 0;
	for (auto it = container.begin(); it != container.end(); it++)
	{
		if (count == 5)
		{
			std::cout << "[...]" << std::endl;
			break ;
		}
		std::cout << *it << " ";
		count++;
	}
	std::cout << std::endl;
}

void PmergeMe::CheckDoubles(std::vector<int> container)
{
	std::vector<int>::iterator it = container.begin();
	for (; it != container.end(); it++)
	{
		int count = std::count(container.begin(), container.end(), *it);
		if (count != 1)
			throw (DoubleNumbersException());
	}
}

void PmergeMe::ParseNumbers(char *argv[])
{
	for (int i = 1; argv[i]; i++)
	{
		std::string input(argv[i]);
		if (input[0] == '-')
			throw (InvalidNumbersException());
		if (input.size() > 10)
			throw (InvalidNumbersException());
		for (int j = 0; argv[i][j]; j++)
		{
			std::cout << argv[i][j] << std::endl;
			if (std::isdigit(argv[i][j]) == 0)
				throw (InvalidNumbersException());
		}
		this->AddNumberToBoth(argv[i]);
	}
	this->CheckDoubles(this->_vecarr);
	std::cout << "Before : ";
	this->PrintContainer(this->_vecarr);
}

template <typename T>
void PmergeMe::MergeInsertion(T container)
{
	T firstcontainer;
	T secondcontainer;
	


}

void PmergeMe::StartSort()
{
	time_t start_time;
	time_t end_time;

	time(&start_time);
	this->MergeInsertion(this->_vecarr);
	std::cout << "After: ";
	this->PrintContainer(this->_vecarr);
	time(&end_time);
	this->PrintTime((end_time - start_time), true);
	time(&start_time);
	this->MergeInsertion(this->_deqarr);
	time(&end_time);
	this->PrintTime((end_time - start_time), false);
}

void PmergeMe::PrintTime(double time, bool is_vec)
{
	std::cout << "Time to process a range of: ";
	std::cout << this->_elements;
	if (is_vec == true)
	{
		std::cout << " elements with std::vector<int>: ";
	}
	else
	{
		std::cout << " elements with std::deque<int>: ";
	}
	std::cout << time << std::setprecision(6);
	std::cout << " us" << std::endl;
}

const char* PmergeMe::InvalidNumbersException::what() const throw()
{
	return ("Error: Invalid number passed as paramater!");
}

const char* PmergeMe::DoubleNumbersException::what() const throw()
{
	return ("Error: Double integers found!");
}