#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

void PmergeMe::printMessage()
{
    for (std::vector<v_Node>::iterator it = vNode.begin(); it != vNode.end(); it++)
        std::cout << it->value << " ";
    std::cout << "\n";
}

long long PmergeMe::getTime()
{
    struct timeval tv;

    gettimeofday(&tv, 0);
    return static_cast<long long>(tv.tv_sec) * 1000000LL
         + tv.tv_usec;
}

void PmergeMe::start()
{
    std::cout << "Before : ";
    printMessage();
    long long vectorStart = getTime();
    fordJohnsonVector(vNode);
    long long vectorEnd = getTime();
    std::cout << "After : ";
    printMessage();

    long long dequeStart = getTime();
    fordJohnsonDeque(dNode);
    long long dequeEnd = getTime();

    std::cout << "Time to process a range of "
              << vNode.size()
              << " elements with std::vector : "
              << vectorEnd - vectorStart
              << " us" << std::endl;

    std::cout << "Time to process a range of "
              << dNode.size()
              << " elements with std::deque : "
              << dequeEnd - dequeStart
              << " us" << std::endl;
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
                std::cerr << "Error.\n";
                exit(EXIT_FAILURE);
            }
            j++;
        }
        int num = std::atoi(av[i]);
        if (num == 0)
        {
            std::cerr << "Error.\n";
            exit(EXIT_FAILURE);
        }
        if (num < 0)
        {
            std::cerr << "Error.\n";
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

bool lowerBoundCompDeque(const PmergeMe::d_Node &a, const PmergeMe::d_Node &b)
{
    return a.value < b.value;
}

void PmergeMe::printNodeDeque(const d_Node& node, const std::string& prefix, bool last)
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

void PmergeMe::printNodesDeque(const std::deque<d_Node>& nodes)
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

void PmergeMe::makePairDeque(std::deque<d_Node> &node)
{
    for (std::deque<d_Node>::iterator it = node.begin(); it != node.end() && (it + 1) != node.end();)
    {
        if (it->value < (it + 1)->value)
            std::swap(*it, *(it + 1));
        it->losers.push_back(*(it + 1));
        it = node.erase(it + 1);
    }
}

void PmergeMe::fordJohnsonDeque(std::deque<d_Node> &node)
{
    if (node.size() <= 1)
        return;
    bool drag = node.size() % 2 != 0;
    makePairDeque(node);

    d_Node dragNode = 0;
    if (drag)
    {
        dragNode = node.back();
        node.pop_back();
    }
    size_t sizeGeneration = node[0].losers.size();
    fordJohnsonDeque(node);

    std::deque<size_t> order = orderInsertiongenD(node.size());
    std::deque<d_Node>::iterator place;

    for (size_t orderixd = 0; orderixd < order.size(); orderixd++) 
    {
        int target = order[orderixd] - 1;
        for (size_t i = 0; i < node.size(); i++)
        {
            if (sizeGeneration != node[i].losers.size())
                continue;
            if (target == 0)
            {
                d_Node back = node[i].losers.back();
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
}

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

        printNodeVector(node.losers[i], nextPrefix,
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
            printNodeVector(nodes[i].losers[j], "",
                j == nodes[i].losers.size() - 1);

        std::cout << std::endl;
    }
    std::cout << "===========================\n";
}

bool lowerBoundCompVector(const PmergeMe::v_Node &a, const PmergeMe::v_Node &b)
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

void PmergeMe::makePairVector(std::vector<v_Node> &node)
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
    makePairVector(node);

    v_Node dragNode = 0;
    if (drag)
    {
        dragNode = node.back();
        node.pop_back();
    }
    size_t sizeGeneration = node[0].losers.size();
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
}

PmergeMe::~PmergeMe() {}