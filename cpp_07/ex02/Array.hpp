#pragma once

#include <iostream>

template <typename T> class Array
{
private:
	T* _ptrArray;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(Array &in);
	Array &operator=(Array &in);
	~Array();

	int	size(void);
	T& operator[](int input);
	class IndexOutOfScope : public std::exception
	{
		const char *what() const throw()
		{
			return ("The index is out of scope!");
		}
	};
};

template <typename T>
Array<T>::Array()
{
	std::cout << "Array Default constructor is called, array allocated with size of 1!" << std::endl;
	this->_ptrArray = new T[1];
	this->_size = 1;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array constructor is called, array allocated with spicific size!" << std::endl;
	this->_ptrArray = new T[n + 1];
	this->_size = n;
}

template <typename T>
Array<T>::Array(Array &in)
{
	std::cout << "Array copy constructor is called!" << std::endl;
	this->_ptrArray = NULL;
	*this = in;
}

template <typename T>
Array<T>& Array<T>::operator=(Array &in)
{
	std::cout << "Operator overload '=' is called!" << std::endl;
	if (this == &in)
		return (*this);
	this->_size = in._size;
	this->_ptrArray = new T[in.size()];
	for (int i = 0; i < in.size(); i++)
		this->_ptrArray[i] = in._ptrArray[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array default deconstructor is called and array is deleted!" << std::endl;
	delete[] this->_ptrArray;
}

template <typename T>
int	Array<T>::size(void)
{
	return (this->_size);
}

template <typename T>
T& Array<T>::operator[](int input)
{
	if (input >= this->size() || input < 0)
		throw(IndexOutOfScope());
	return(this->_ptrArray[input]);
}