#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main ()
{
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter *me = new Character("me");
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << "\n----- Memory TEST -----\n" << std::endl;

        IMateriaSource *s = new MateriaSource();
        s->learnMateria(new Ice());
        s->learnMateria(new Cure());
        s->learnMateria(new Ice());
        s->learnMateria(new Cure());
        s->learnMateria(new Ice());
        s->learnMateria(new Cure());

        std::cout << "This test is only to check that the memory is freed and everything is okay." << std::endl;
        delete s;
    }
    return 0;
}