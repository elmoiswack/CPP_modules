#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor is called" << std::endl;
	this->fixed_point = a.fixed_point;
}

Fixed::Fixed(const int fixed_int)
{
	std::cout << "Integer constructor is called" << std::endl;
	this->fixed_point = fixed_int;
}

Fixed::Fixed(const float fixed_float)
{
	std::cout << "Float constructor is called" << std::endl;
	this->fixed_point = fixed_float;
}

Fixed& Fixed::operator=(const Fixed& a)
{
	std::cout << "Copy assignment operator is called" << std::endl;
	fixed_point = a.fixed_point;
	return (*this);
}

std::ostream& operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor is called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits is called" << std::endl;
	return (this->fixed_point >> this->frac_bits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits is called" << std::endl;
	this->fixed_point =  raw << this->frac_bits;
}

float Fixed::toFloat( void ) const
{
	float a;

	a = this->fixed_point << this->frac_bits;
	return (a);
}

int Fixed::toInt( void ) const
{
	int	a;

	a = roundf(this->fixed_point << this->frac_bits);
	return (a);
}