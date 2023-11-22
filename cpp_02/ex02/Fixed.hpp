#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	fixed_point;
	static const int frac_bits = 8;
public:
	Fixed();
	Fixed(const int fixed_int);
	Fixed(const float fixed_float);
	Fixed(const Fixed &a);
	
	~Fixed();
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	
	static Fixed& min(Fixed &a, Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

	Fixed& operator=(const Fixed& a);

	bool	operator>(Fixed& refference);
	bool	operator<(Fixed& refference);
	bool	operator>=(Fixed& refference);
	bool	operator<=(Fixed& refference);
	bool	operator==(Fixed& refference);
	bool	operator!=(Fixed& refference);

	Fixed	operator+(Fixed& reference);
	Fixed	operator-(Fixed& reference);
	Fixed	operator*(Fixed& reference);
	Fixed	operator/(Fixed& reference);
};

std::ostream& operator<<(std::ostream &output, const Fixed &fixed);

#endif