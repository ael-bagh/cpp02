#include "Fixed.hpp"

Fixed::Fixed(int const n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
	return ;
}

Fixed::Fixed(const Fixed & src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed &	Fixed::operator* (Fixed const & rhs)
{
	this->_fixedPointValue = (this->_fixedPointValue * rhs.getRawBits()) >> this->_fractionalBits;
	return (*this);
}

Fixed &	Fixed::operator- (Fixed const & rhs)
{
	this->_fixedPointValue = (this->_fixedPointValue - rhs.getRawBits()) >> this->_fractionalBits;
	return (*this);
}

Fixed & Fixed::operator+ (Fixed const & rhs)
{
	this->_fixedPointValue = (this->_fixedPointValue + rhs.getRawBits()) >> this->_fractionalBits;
	return (*this);
}

Fixed & Fixed::operator/ (Fixed const & rhs)
{
	this->_fixedPointValue = (this->_fixedPointValue / rhs.getRawBits()) >> this->_fractionalBits;
	return (*this);
}
Fixed & Fixed::operator++()
{
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed & Fixed::operator--()
{
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed & Fixed::operator++(int)
{
	Fixed &tmp(*this);
	this->_fixedPointValue += 1;
	return (tmp);
}

Fixed & Fixed::operator--(int)
{
	Fixed &tmp(*this);
	this->_fixedPointValue -= 1 ;
	return (tmp);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}
int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

Fixed & Fixed::min(Fixed & val1, Fixed & val2)
{
	if (val1._fixedPointValue < val2._fixedPointValue)
		return val1;
	else
		return val2;
}

Fixed & Fixed::max(Fixed & val1, Fixed & val2)
{
	if (val1._fixedPointValue > val2._fixedPointValue)
		return val1;
	else
		return val2;
}

Fixed const & Fixed::min(Fixed const & val1, Fixed const & val2)
{
	if (val1._fixedPointValue < val2._fixedPointValue)
		return val1;
	else
		return val2;
}

Fixed const & Fixed::max(Fixed const & val1, Fixed const & val2)
{
	if (val1._fixedPointValue > val2._fixedPointValue)
		return val1;
	else
		return val2;
}
