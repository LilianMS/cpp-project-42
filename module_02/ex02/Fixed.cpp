#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

// Overload of the << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other._rawBits);
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return (*this);
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

// Increment and decrement operators
Fixed &Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_rawBits++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_rawBits--;
	return (temp);
}

// Static member functions for min and max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
