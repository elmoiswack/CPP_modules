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
	
	Fixed& operator=(const Fixed& a);
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &output, const Fixed &fixed);

#endif