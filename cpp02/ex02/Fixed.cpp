#include "Fixed.hpp"

Fixed::Fixed() : value(0){	
	std::cout << Cyan << "default constructor called\n"; 
}

Fixed::Fixed(const int value)
{
	std::cout << Cyan << "Int constructor called\n"; 
	this->value = value << this->fractions;
}

Fixed::Fixed(const float fl)
{
	std::cout << Cyan << "Float constructor called\n"; 
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
	std::cout << Yellow << "getRawBits member function called\n" << RESET;
	return value; 
}

void Fixed::setRawBits(int const raw){
	this->value = raw; 
}

Fixed::~Fixed()
{
	std::cout << Redr << "destructur called\n" << RESET;
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
	std::cout << Blue << "copy Constructor called\n" << RESET;
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
	std::cout << Green << "copy assignement operator called\n" << RESET;
	this->value = next.value;
	return *this;
}

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
