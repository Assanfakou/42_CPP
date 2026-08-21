#pragma once

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <algorithm>
#include <deque>

class PmergeMe
{
      public:
        struct d_Node
        {
          int value;
          std::deque<d_Node> losers;

          d_Node(int value) : value(value), losers()
          {
          }
        };

        struct v_Node
        {
          int value;
          std::vector<v_Node> losers;

          v_Node(int value) : value(value), losers()
          {
          }
        };
      private:
        bool isOdd;
        std::vector<v_Node> vNode;
        std::deque<d_Node> dNode;

        std::vector<size_t> orderInsertiongenV(size_t size) const;
        void fordJohnsonVector(std::vector<v_Node> &nodes);
        void makePairVector(std::vector<v_Node> &nodes);
        bool lowerBoundCompVector(const v_Node &a, const v_Node &b);

        bool lowerBoundCompDeque(const d_Node &a, const d_Node &b);
        std::vector<size_t> orderInsertiongenD(size_t size) const;
        void fordJohnsonDeque(std::vector<v_Node> &nodes);
        void makePairDeque(std::deque<v_Node> &nodes);


        void start();

        public:
        PmergeMe(void); 
        PmergeMe(char **av, int ac);

        void printNode(const v_Node &node, const std::string &prefix, bool last);
        void printNodes(const std::vector<v_Node> &nodes);

        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        ~PmergeMe();
};
