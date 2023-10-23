#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(Fixed &a)
{
	std::cout << "Copy constructor is called" << std::endl;
	this->fixed_point = a.fixed_point;
}

Fixed& Fixed::operator=(Fixed& a)
{
	std::cout << "Copy assignment operator is called" << std::endl;
	fixed_point = a.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor is called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits is called" << std::endl;
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits is called" << std::endl;
	this->fixed_point = raw;
}