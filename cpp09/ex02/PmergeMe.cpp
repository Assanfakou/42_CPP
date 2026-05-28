#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}
void PmergeMe::printPair(std::vector<std::pair<int, int> > &pairs, int leftOver) const
{
        std::cout << "Pairs:\n";
        for (size_t i = 0; i < pairs.size(); i++)
        {
                std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")\n";
        }
        if (leftOver != -69)
                std::cout << "Leftover: " << leftOver << "\n";
}

void PmergeMe::makePair(std::vector<int> &vect)
{
        std::vector<std::pair<int, int> > pairs;

        int leftOver = -69;
        if (vect.size() % 2 != 0)
        {
                leftOver = vect.back();
                vect.pop_back();
        } 
        std::vector<int>::iterator vectIterator = vect.begin();
        for (; vectIterator != vect.end(); vectIterator += 2)
        {
                std::pair<int, int> tmp(*vectIterator, *(vectIterator + 1));
                if (tmp.first > tmp.second)
                        std::swap(tmp.first, tmp.second);
                pairs.push_back(tmp);
        }
        printPair(pairs, leftOver);
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
                if (num < 0)
                {
                        std::cerr << "Error: Negative number is not allowed.\n";
                        exit(EXIT_FAILURE);
                }
                this->dequ.push_back(num);
                this->vect.push_back(num);
        }
        makePair(this->vect);
}

void PmergeMe::printVector() const
{
        for (size_t i = 0; i < this->vect.size(); i++)
        {
                std::cout << this->vect[i] << " ";
        }
        std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
        for (size_t i = 0; i < this->dequ.size(); i++)
        {
                std::cout << this->dequ[i] << " ";
        }
        std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
        *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
        if (this != &other)
        {
                this->dequ = other.dequ;
                this->vect = other.vect;
        }
        return (*this);
}

PmergeMe::~PmergeMe()
{
}
