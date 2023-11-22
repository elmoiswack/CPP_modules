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
	this->fixed_point = fixed_int << this->frac_bits;
}

Fixed::Fixed(const float fixed_float)
{
	std::cout << "Float constructor is called" << std::endl;
	this->fixed_point = roundf(fixed_float * (1 << this->frac_bits));;
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

	a = (float)this->fixed_point / (1 << this->frac_bits);
	return (a);
}

int Fixed::toInt( void ) const
{
	int	a;

	a = this->fixed_point >> this->frac_bits;
	return (a);
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

bool Fixed::operator>(Fixed& refference)
{
	if (this->fixed_point > refference.fixed_point)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(Fixed& refference)
{
	if (this->fixed_point < refference.fixed_point)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(Fixed& refference)
{
	if (this->fixed_point >= refference.fixed_point)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(Fixed& refference)
{
	if (this->fixed_point <= refference.fixed_point)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(Fixed& refference)
{
	if (this->fixed_point == refference.fixed_point)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(Fixed& refference)
{
	if (this->fixed_point != refference.fixed_point)
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(const Fixed& reference)
{
	Fixed temp = this->toFloat() + reference.toFloat();
	return (temp);

}

Fixed	Fixed::operator-(const Fixed& reference)
{
	Fixed temp = this->toFloat() - reference.toFloat();
	return (temp);
}

Fixed	Fixed::operator*(const Fixed& reference)
{
	Fixed temp = this->toFloat() * reference.toFloat();
	return (temp);
}

Fixed	Fixed::operator/(const Fixed& reference)
{
	Fixed temp = this->toFloat() / reference.toFloat();
	return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.fixed_point < b.fixed_point)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.fixed_point > b.fixed_point)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.fixed_point < b.fixed_point)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.fixed_point > b.fixed_point)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::operator++( void )
{
	this->fixed_point++;
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	this->fixed_point--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed old = *this;
	this->fixed_point++;
	return (old);
}

Fixed	Fixed::operator--(int)
{
	Fixed old = *this;
	this->fixed_point--;
	return (old);
}