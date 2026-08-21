#include "PmergeMe.hpp"

void PmergeMe::printNodeVector(const v_Node& node, const std::string& prefix, bool last)
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

        printNodeVecotor(node.losers[i], nextPrefix,
            i == node.losers.size() - 1);
    }
}

void PmergeMe::printNodesVector(const std::vector<v_Node>& nodes)
{
    std::cout << "\n========== NODES ==========\n";

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        std::cout << nodes[i].value << std::endl;

        for (size_t j = 0; j < nodes[i].losers.size(); ++j)
            printNodeVecotor(nodes[i].losers[j], "",
                j == nodes[i].losers.size() - 1);

        std::cout << std::endl;
    }
    std::cout << "===========================\n";
}

bool PmergeMe::lowerBoundCompVector(const PmergeMe::v_node &a, const PmergeMe::v_Node &b)
{
    return a.value < b.value;
}

std::vector<size_t> PmergeMe::orderInsertiongenV(size_t size) const
{
    std::vector<std::size_t> order;
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

void PmergeMe::makePair(std::vector<v_Node> &node)
{
    for (std::vector<v_Node>::iterator it = node.begin(); it != node.end() && (it + 1) != node.end();)
    {
        if (it->value < (it + 1)->value)
            std::swap(*it, *(it + 1));
        it->losers.push_back(*(it + 1));
        it = node.erase(it + 1);
    }
}

void PmergeMe::fordJohnsonVector(std::vector<v_Node> &node)
{
    if (node.size() <= 1)
        return;
    bool drag = node.size() % 2 != 0;
    makePair(node);

    v_Node dragNode = 0;
    if (drag)
    {
        dragNode = node.back();
        node.pop_back();
    }
    size_t sizeGeneration = node[0].losers.size();
    printNodesVector(node);
    fordJohnsonVector(node);

    std::vector<size_t> order = orderInsertiongenV(node.size());
    std::vector<v_Node>::iterator place;

    for (size_t orderixd = 0; orderixd < order.size(); orderixd++) 
    {
        int target = order[orderixd] - 1;
        for (size_t i = 0; i < node.size(); i++)
        {
            if (sizeGeneration != node[i].losers.size())
                continue;
            if (target == 0)
            {
                v_Node back = node[i].losers.back();
                place = std::lower_bound(node.begin(), node.begin() + i, back, lowerBoundCompVector);
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
        place = std::lower_bound(node.begin(), node.end(), dragNode, lowerBoundCompVector);
        node.insert(place, dragNode);
    }
    std::cout << "_____ After Inserting jacobsall sequence ____\n";
    printNodes(node);
}