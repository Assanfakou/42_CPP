#pragma once

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>


class PmergeMe
{
      private:
        std::vector<int> vect;
        std::deque<int> dequ;
        void makePair(std::vector<int> &vect);
        void printPair(std::vector<std::pair<int, int> > &pairs, int leftOver) const;
      public:
        PmergeMe(void);
        PmergeMe(char **av, int ac);
        void printVector() const;
        void printDeque() const;
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
};

