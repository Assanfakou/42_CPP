#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main ()
{
    AMateria *mat = new Ice();
    AMateria *s = mat->clone();
    delete s;
    delete mat;
    return 0;
}