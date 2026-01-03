#include "Brain.hpp"
#include "string"

Brain::Brain()
{
    std::cout << Yellow << "Default constructor of Brain\n" << RESET;
    for (int i = 0; i < 100; i++)
        ideas[i] = "assan";
}

Brain::Brain(const Brain& other)
{
    std::cout << Yellow << "Copy constructor of Brain\n" << RESET;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << Yellow << "Copy assignement operator of Brain\n" << RESET;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

void Brain::getIdea(int i) const
{
    std::cout << ideas[i] << "\n";
}
void Brain::getIdeas() const
{
    for (int i = 0; i < 100; i++)
        std::cout << ideas[i] << " - ";
    std::cout << "\n";
}

Brain::~Brain()
{
    std::cout << Yellow << "Brain's Destructor\n";
}