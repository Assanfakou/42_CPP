#include "Fixed.hpp"

Fixed::Fixed() : value(0){	
	std::cout << Cyan << "Default constructor called\n"; 
}

int Fixed::getRawBits() const{
	std::cout << Yellow << "getRawBits member function called\n"<< RESET;
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
	this->value = oldObj.value;
	std::cout << Blue << "copy Constructor called\n" << RESET;
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
	this->value = next.getRawBits();
	return *this;
}

