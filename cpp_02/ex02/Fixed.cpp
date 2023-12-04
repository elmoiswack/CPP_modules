#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point = 0;
}

Fixed::Fixed(const Fixed &a)
{
	this->fixed_point = a.fixed_point;
}

Fixed::Fixed(const int fixed_int)
{
	this->fixed_point = fixed_int << this->frac_bits;
}

Fixed::Fixed(const float fixed_float)
{
	this->fixed_point = roundf(fixed_float * (1 << this->frac_bits));
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor is called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point >> this->frac_bits);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point =  raw << this->frac_bits;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->fixed_point / (1 << this->frac_bits));
}

int Fixed::toInt( void ) const
{
	return (this->fixed_point >> this->frac_bits);
}

Fixed& Fixed::operator=(const Fixed& a)
{
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