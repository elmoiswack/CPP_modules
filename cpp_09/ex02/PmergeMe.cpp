#include "PmergeMe.hpp"
#include <iomanip>
#include <time.h>

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
		std::cout << "ERROR: invalid number found in string!" << std::endl;
		std::cerr << "ERROR: " << e.what() << std::endl;
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
}

template <typename T>
T PmergeMe::Merge(T &left, T &right){
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

	return (this->Merge(left, right));
}

template <typename T> 
T PmergeMe::InsertionSort(T& result, T& temp, int strugler)
{
	for (auto it_temp = temp.begin(); it_temp != temp.end(); it_temp++)
	{
		auto it = std::lower_bound(result.begin(), result.end(), *it_temp);
		result.insert(it, *it_temp);

	}
	if (strugler != -1)
	{
		auto it = std::lower_bound(result.begin(), result.end(), strugler);
		result.insert(it, strugler);
	}
	return (result);
}

template <typename T, typename P> 
T PmergeMe::DoTheSort(T& container, P& pairs)
{
	int strugler;
	if (container.size() % 2 != 0)
	{
		auto it = container.end();
		it--;
		strugler = *it;
	}
	else
		strugler = -1;


	for (int i = 0; i + 1 < (int)container.size(); i += 2)
	{
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
        pairs.push_back(std::make_pair(container[i], container[i + 1]));
    }

	T result;
	for (int index = 0; index < (int)pairs.size(); index++)
	{
		result.push_back(pairs[index].first);
	}
	result = this->MergeSort(result);
	
	T temp;
	for (auto it_pairs = pairs.begin(); it_pairs != pairs.end(); it_pairs++)
	{
		temp.push_back((*it_pairs).second);
	}

	result = this->InsertionSort(result, temp, strugler);
	return (result);
}

void PmergeMe::StartSort()
{
	time_t start, end;

	start = clock();
	std::cout << "--VECTOR CONTAINER--" << std::endl;
	std::cout << "Before Vector: ";
	this->PrintContainer(this->_vecarr);
	std::cout << "After Vector: ";
	std::vector<std::pair<int, int>> pairs_vec;
	this->_vecsorted = this->DoTheSort(this->_vecarr, pairs_vec);
	this->PrintContainer(this->_vecsorted);
	end = clock();
	this->_vectime = ((double)(end - start)) / CLOCKS_PER_SEC;
	this->PrintTime(this->_vectime, true);;
	
	std::cout << std::endl;
	
	start = clock();
	std::cout << "--DEQUE CONTAINER--" << std::endl;
	std::cout << "Before Deque: ";
	this->PrintContainer(this->_deqarr);
	std::cout << "After Deque: ";
	std::deque<std::pair<int, int>> pairs_deq;
	this->_deqsorted = this->DoTheSort(this->_deqarr, pairs_deq);
	this->PrintContainer(this->_deqsorted);
	end = clock();
	this->_deqtime = ((double)(end - start)) / CLOCKS_PER_SEC;
	this->PrintTime(this->_deqtime, false);
}

template <typename T>
void PmergeMe::PrintContainer(T& container)
{
	int count = 0;
	for (auto it = container.begin(); it != container.end(); it++)
	{
		if (count == 10)
		{
			std::cout << "[...]" << std::endl;
			break ;
		}
		std::cout << *it << " ";
		count++;
	}
	std::cout << std::endl;
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
	std::cout << std::fixed << std::setprecision(6) << time;
	std::cout << " seconds" << std::endl;
}

const char* PmergeMe::InvalidNumbersException::what() const throw()
{
	return ("Error: Invalid number passed as paramater!");
}

const char* PmergeMe::DoubleNumbersException::what() const throw()
{
	return ("Error: Double integers found!");
}