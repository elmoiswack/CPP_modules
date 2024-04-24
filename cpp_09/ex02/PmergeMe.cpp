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
			this->_vecarr.push_back(*init);
		}
	}
	if (in._deqarr.size() > 0)
	{
		std::deque<int>::iterator initdeq = in._deqarr.begin();
		for (; initdeq != in._deqarr.end(); initdeq++)
		{
			this->_deqarr.push_back(*initdeq);
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
	try
	{
		number = std::stoi(numb);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
	this->_vecarr.push_back(number);
	this->_deqarr.push_back(number);
	this->_elements += 1;
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
T PmergeMe::merge(T &left, T &right){
	T	result;
	int indexl = 0;
	int indexr = 0;

	while (indexl < (int)left.size() && indexr < (int)right.size())
	{
		if (left[indexl] < right[indexr])
		{
			result.push_back(left[indexl]);
			indexl++;
		}
		else 
		{
			result.push_back(right[indexr]);
			indexr++;
		}
	}
	while (indexl < (int)left.size())
	{
		result.push_back(left[indexl]);
		indexl++;
	}
	while (indexr < (int)right.size())
	{
		result.push_back(right[indexr]);
		indexr++;
	}
	return result;
}

template <typename T>
T PmergeMe::MergeSort(T& container)
{
	if (container.size() < 2)
		return container;

	T left = T(container.begin(), container.begin() + container.size() / 2);
	T right = T(container.begin() + container.size() / 2, container.end());

	left = this->MergeSort(left);
	right = this->MergeSort(right);

	return (merge(left, right));
}

void PmergeMe::StartSort()
{
	this->_vecstarttime = std::chrono::high_resolution_clock::now();
	this->_vecsorted = this->MergeSort(this->_vecarr);
	this->_vecendtime = std::chrono::high_resolution_clock::now();
	this->_deqstarttime = std::chrono::high_resolution_clock::now();
	this->_deqsorted = this->MergeSort(this->_deqarr);
	this->_deqendtime = std::chrono::high_resolution_clock::now();
	this->PrintAll();
}

void PmergeMe::PrintAll()
{
	std::cout << "--VECTOR CONTAINER--" << std::endl;
	std::cout << "Before Vector: ";
	this->PrintContainer(this->_vecarr);
	std::cout << "After Vector: ";
	this->PrintContainer(this->_vecsorted);
	this->PrintTime(, true);
	std::cout << "--DEQUE CONTAINER--" << std::endl;
	std::cout << "Before deque: ";
	this->PrintContainer(this->_deqarr);
	std::cout << "After deque: ";
	this->PrintContainer(this->_deqsorted);
	this->PrintTime(, false);
}

template <typename T>
void PmergeMe::PrintContainer(T& container)
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

void PmergeMe::PrintTime(std::string time, bool is_vec)
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
	std::cout << time;
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