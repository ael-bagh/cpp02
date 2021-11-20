#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:
		Fixed(int const n);
		Fixed(float const n);
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed &	operator=(Fixed const & rhs);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif