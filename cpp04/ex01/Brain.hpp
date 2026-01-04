#include <iostream>
#include "colors.h"

#ifndef BRAIN_HPP
# define BRAIN_HPP 

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const std::string& idea);
        Brain(const Brain& obj);
        void getIdea(int i) const;
        void getIdeas() const;
        Brain& operator=(const Brain& obj);
        ~Brain();
};

#endif