#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const& other) : AMateria(other) {}

Cure& Cure::operator=(Cure const& other)
{
    AMateria::operator=(other);
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "heals " << target.getName() << "'s wounds \n";
}

Cure::~Cure() {
}
