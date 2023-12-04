#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a(10);
	Fixed b (10);
	Fixed c(2.42f);
	Fixed d(4.75f);

	std::cout << std::endl;
	std::cout << "Calculation operators" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;

	std::cout << std::endl;
	std::cout << "Comparison operators" << std::endl;
	Fixed l(20);
	Fixed p(10);
	if (l < p)
		std::cout << "l < p = true" << std::endl;
	else
		std::cout << "l < p = false" << std::endl;
	if (l > p)
		std::cout << "l > p = true" << std::endl;
	else
		std::cout << "l > p = false" << std::endl;
	if (l >= p)
		std::cout << "l >= p = true" << std::endl;
	else
		std::cout << "l >= p = false" << std::endl;
	if (l <= p)
		std::cout << "l <= p = true" << std::endl;
	else
		std::cout << "l <= p = false" << std::endl;
	if (l == p)
		std::cout << "l == p = true" << std::endl;
	else
		std::cout << "l == p = false" << std::endl;
	if (l != p)
		std::cout << "l != p = true" << std::endl;
	else
		std::cout << "l != p = false" << std::endl;

	std::cout << std::endl;
	Fixed z;
	Fixed const y( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Increment and decrements" << std::endl;
	std::cout << z << std::endl;
	std::cout << ++z << std::endl;
	std::cout << z << std::endl;
	std::cout << z++ << std::endl;
	std::cout << z << std::endl;
	
	std::cout << y << std::endl;
	std::cout << Fixed::max( z, y ) << std::endl;
;

	std::cout << std::endl;

return 0;
}