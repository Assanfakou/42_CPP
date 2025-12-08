/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:25:43 by hfakou            #+#    #+#             */
/*   Updated: 2025/12/08 21:10:14 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	this->value = this->value + (1 << fractions);
	return copy;
}

Fixed Fixed::operator--(int)
{
	Fixed copy;

	copy = *this;
	this->value = this->value - (1 << fractions);
	return copy;
}
