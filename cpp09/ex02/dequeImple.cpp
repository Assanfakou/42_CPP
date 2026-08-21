#include "PmergeMe.hpp"

bool PmergeMe::lowerBoundCompDeque(const PmergeMe::d_Node &a, const PmergeMe::d_Node &b)
{
    return a.value < b.value;
}

void PmergeMe::printNodeDeque(const d_node& node, const std::string& prefix, bool last)
{
    std::cout << prefix;

    if (last)
        std::cout << "└── ";
    else
        std::cout << "├── ";

    std::cout << node.value << std::endl;

    for (size_t i = 0; i < node.losers.size(); ++i)
    {
        std::string nextPrefix = prefix;

        if (last)
            nextPrefix += "    ";
        else
            nextPrefix += "│   ";

        printNodeDeque(node.losers[i], nextPrefix,
            i == node.losers.size() - 1);
    }
}

void PmergeMe::printNodesDeque(const std::deque<d_node>& nodes)
{
    std::cout << "\n========== NODES ==========\n";

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        std::cout << nodes[i].value << std::endl;

        for (size_t j = 0; j < nodes[i].losers.size(); ++j)
            printNodeDeque(nodes[i].losers[j], "",
                j == nodes[i].losers.size() - 1);

        std::cout << std::endl;
    }

    std::cout << "===========================\n";
}


std::deque<size_t> PmergeMe::orderInsertiongenD(size_t size) const
{
    std::deque<std::size_t> order;
    if (size == 0)
        return order;
    order.push_back(1);
    std::size_t previos = 1;
    std::size_t current = 3;

    while (previos < size)
    {
        size_t end = current;
        if (end > size)
            end = size;
        size_t i = end;
        while (i > previos)
        {
            order.push_back(i);
            --i;
        }
        size_t next = (previos * 2) + current;
        previos = current;
        current = next;
    }
    return order;
}

void PmergeMe::makePairDeque(std::deque<d_node> &node)
{
    for (std::deque<d_node>::iterator it = node.begin(); it != node.end() && (it + 1) != node.end();)
    {
        if (it->value < (it + 1)->value)
            std::swap(*it, *(it + 1));
        it->losers.push_back(*(it + 1));
        it = node.erase(it + 1);
    }
}

void PmergeMe::fordJohnsonDeque(std::deque<d_node> &node)
{
    if (node.size() <= 1)
        return;
    bool drag = node.size() % 2 != 0;
    makePair(node);

    d_node dragNode = 0;
    if (drag)
    {
        dragNode = node.back();
        node.pop_back();
    }
    size_t sizeGeneration = node[0].losers.size();
    printNodesDeque(node);
    fordJohnsonDeque(node);

    std::deque<size_t> order = orderInsertiongenD(node.size());
    std::deque<d_node>::iterator place;

    for (size_t orderixd = 0; orderixd < order.size(); orderixd++) 
    {
        int target = order[orderixd] - 1;
        for (size_t i = 0; i < node.size(); i++)
        {
            if (sizeGeneration != node[i].losers.size())
                continue;
            if (target == 0)
            {
                d_node back = node[i].losers.back();
                place = std::lower_bound(node.begin(), node.begin() + i, back, lowerBoundCompDeque);
                node.insert(place, back);
                break;
            }
            target--;
        }
    }
    for (size_t i = 0; i < node.size(); i++)
    {
        if (node[i].losers.size() == sizeGeneration)
            node[i].losers.pop_back();
    }
    if (drag)
    {
        place = std::lower_bound(node.begin(), node.end(), dragNode, lowerBoundCompDeque);
        node.insert(place, dragNode);
    }
    std::cout << "_____ After Inserting jacobsall sequence ____\n";
    printNodesDeque(node);
}