#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	fixed_point;
	static const int frac_bits = 8;
public:
	Fixed();
	Fixed(Fixed &a);
	Fixed& operator=(Fixed& a);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif