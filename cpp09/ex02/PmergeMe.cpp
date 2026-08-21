#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

void PmergeMe::start()
{
    fordJohnsonVector(vNode);
    printNodes(vNode);
}


PmergeMe::PmergeMe(char **av, int ac)
{
    for (int i = 1; i < ac; i++)
    {
        int j = 0;
        while (av[i][j])
        {
            if (!std::isdigit(av[i][j]))
            {
                std::cerr << "Error: Invalid input.\n";
                exit(EXIT_FAILURE);
            }
            j++;
        }
        int num = std::atoi(av[i]);
        if (num == 0)
        {
            std::cerr << "Error: 0 is not a positive Number.\n";
            exit(EXIT_FAILURE);
        }
        if (num < 0)
        {
            std::cerr << "Error: Negative number is not allowed.\n";
            exit(EXIT_FAILURE);
        }
        vNode.push_back(num);
        dNode.push_back(num);
    }
    start();
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->dNode = other.dNode;
        this->vNode = other.vNode;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}


// void printv_NodeTree(std::ostream &os, const PmergeMe::Node &item, const std::string &prefix, bool isLast)
// {
//     os << prefix << (isLast ? "└── " : "├── ") 
//        << "\033[1;97mv_Node:\e[0m \033[1;32m" << item.value << "\e[0m\n";

//     std::size_t size = item.losers.size();
//     for (std::size_t i = 0; i < size; ++i)
//     {
//         bool lastLoser = (i == size - 1);
//         printv_NodeTree(os, item.losers[i], prefix + (isLast ? "    " : "│   "), lastLoser);
//     }
// }

// std::ostream &operator<<(std::ostream &os, const PmergeMe::v_Node &item)
// {
//     os << "\033[1;97mv_Node:\e[0m \033[1;32m" << item.value << "\e[0m\n";
    
//     std::size_t size = item.losers.size();
//     for (std::size_t i = 0; i < size; ++i)
//     {
//         printv_NodeTree(os, item.losers[i], "", (i == size - 1));
//     }
//     return os;
// }