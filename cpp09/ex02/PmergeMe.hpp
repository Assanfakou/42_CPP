#pragma once

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <algorithm>

class PmergeMe
{
      public:
        struct Node
        {
          int value;
          std::vector<Node> losers;

          Node(int value) : value(value), losers()
          {
          }
        };
      private:
        bool isOdd;
        std::vector<int> vect;
        std::deque<int> dequ;
        std::vector<Node> node;

        void makePair(std::vector<int> &vect);
        void printPair(std::vector<std::pair<int, int> > &pairs, int leftOver) const;
        std::vector<size_t> orderInsertiongenV(size_t size) const;

        public:
        PmergeMe(void); 
        PmergeMe(char **av, int ac);

        void printVector() const;
        void printDeque() const;

        void printNode(const Node &node, const std::string &prefix, bool last);
        void printNodes(const std::vector<Node> &nodes);

        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        std::vector<Node> makeNodes(const std::vector<int> &numbers);
        void fordJohnson(std::vector<Node> &nodes);

        std::vector<Node> getWinner(std::vector<Node> &winners);
        void start();

        ~PmergeMe();
};
