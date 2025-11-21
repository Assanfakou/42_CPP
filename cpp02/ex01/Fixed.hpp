#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

#define Black "\033[0;30m"        // Black
#define Redr "\033[0;31m"         // Red
#define Green "\033[0;32m"        // Green
#define Yellow "\033[0;33m"       // Yellow
#define Blue "\033[0;34m"         // Blue
#define Purple "\034[0;35m"       // Purple
#define Cyan "\033[0;36m"         // Cyan
#define White "\033[0;37m"        // White
#define RESET "\033[0m" // reset 

class Fixed{
	private:
		int value;
		static const int fractions = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& oldObj); // copy constructor
		Fixed& operator=(const Fixed& next); // copy assignement operator
		~Fixed();


		friend ostream& operator<<(ostream &out, const Fixed& c)
		int toInt(void) const;
		float toFloat(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
