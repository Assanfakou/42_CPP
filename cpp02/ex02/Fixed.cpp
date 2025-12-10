#include "Fixed.hpp"

Fixed::Fixed() : value(0){	
}

Fixed::Fixed(const int value)
{
	this->value = value << this->fractions;
}

Fixed::Fixed(const float fl)
{
	this->value = roundf(fl * (1 << this->fractions));
}
float Fixed::toFloat(void) const{
	return (float)this->value / (1 << this->fractions);
}

int Fixed::toInt(void) const{
	return this->value / (1 << this->fractions);
}
std::ostream &operator<<(std::ostream& out, const Fixed& c)
{
	out << c.toFloat();
	return out;
}

int Fixed::getRawBits() const{
	return value; 
}

void Fixed::setRawBits(int const raw){
	this->value = raw; 
}

Fixed::~Fixed()
{
}

/*
**
	copy constructor
**
	takes another object and copies content to it
**
*/

Fixed::Fixed(const Fixed& oldObj)
{
	*this = oldObj;
}

/*
**
	copy assignement operator
**
	cleans an axisting object and stores a new data
**
*/

Fixed& Fixed::operator=(const Fixed& next)
{
	if (this != &next)
	{
		this->value = next.value;
		return *this;
	}
	return *this;
}

/* 
**
	Comparison Operations
**
*/
bool Fixed::operator!=(const Fixed& fi1)
{
	if (this->value != fi1.value)
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed& fi1)
{
	if (this->value == fi1.value)
		return true;
	else
		return false;
}

bool Fixed::operator>(const Fixed& fi1)
{
	if (this->value > fi1.value)
		return true;
	else
		return false;
}
bool Fixed::operator<(const Fixed& fi1)
{
	if (this->value < fi1.value)
		return true;
	else
		return false;
}
bool Fixed::operator>=(const Fixed& fi1)
{
	if (this->value >= fi1.value)
		return true;
	else
		return false;
}
bool Fixed::operator<=(const Fixed& fi1)
{
	if (this->value >= fi1.value)
		return true;
	else
		return false;
}

/* 
**
	Arithmitic operations
**
*/

Fixed& Fixed::operator+(const Fixed& a)
{

	this->value = this->value + a.value;
	return *this;
}

Fixed& Fixed::operator-(const Fixed& a)
{

	this->value = this->value - a.value;
	return *this;
}

Fixed& Fixed::operator*(const Fixed& a)
{
	this->value = (this->value * a.value) >> fractions;
	return *this;
}

Fixed& Fixed::operator/(const Fixed& a)
{
	this->value = (this->value << fractions) / a.value;
	return *this;
}

Fixed& Fixed::operator++()
{
	this->value = this->value + 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->value = this->value - 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy;

	copy = *this;
	this->value = this->value + 1;
	return copy;
}

Fixed Fixed::operator--(int)
{
	Fixed copy;

	copy = *this;
	this->value = this->value - 1;
	return copy;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.value > b.value)
		return b;
	else
		return a;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.value > b.value)
		return b;
	else
		return a;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return b;
	else
		return a;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.value < b.value)
		return b;
	else
		return a;
}
