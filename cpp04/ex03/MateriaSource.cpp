#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "copy constructor is called\n";

    for (int i = 0; i < 4; i++){
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{

    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete materias;
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete materias[i];
    }
}