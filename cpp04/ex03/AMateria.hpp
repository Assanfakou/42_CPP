#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>


class ICharacter
{
    std::string name;
    public:
        std::string& getName()
        {
            return name;
        }
};


class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const& type);
    AMateria(AMateria const& other);
    AMateria& operator=(AMateria const& other);

    std::string const& getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    virtual ~AMateria();
};
#endif