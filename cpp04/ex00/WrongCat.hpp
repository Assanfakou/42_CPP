#include "WrongAnimal.hpp"

#ifndef WrongWrongCat_HPP
#define WrongWrongCat_HPP 

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string& type);
		WrongCat& operator=(const WrongCat& animal);
		WrongCat(const WrongCat& animal);
		void makeSound() const;
		~WrongCat();
};
#endif
