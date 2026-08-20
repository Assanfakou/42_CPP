#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

// void PmergeMe::printPair(std::vector<std::pair<int, int> > &pairs, int leftOver) const
// {
//         std::cout << "Pairs:\n";
//         for (size_t i = 0; i < pairs.size(); i++)
//         {
//                 std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")\n";
//         }
//         if (leftOver != -69)
//                 std::cout << "Leftover: " << leftOver << "\n";
// }

std::vector<PmergeMe::Node> PmergeMe::makeNodes(const std::vector<int>& numbers)
{
    std::vector<Node> nodes;
    size_t size = numbers.size();

    if (isOdd)
        --size;
    for (size_t i = 0; i < size; i += 2)
    {
        PmergeMe::Node node(numbers[i]);

        if (numbers[i] < numbers[i + 1])
        {
            node.value = numbers[i + 1];
            node.losers.push_back(PmergeMe::Node(numbers[i]));
        }
        else
            node.losers.push_back(PmergeMe::Node(numbers[i + 1]));
        nodes.push_back(node);
    }
    return nodes;
}

void PmergeMe::printNode(const Node& node, const std::string& prefix, bool last)
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

        printNode(node.losers[i], nextPrefix,
            i == node.losers.size() - 1);
    }
}

void PmergeMe::printNodes(const std::vector<Node>& nodes)
{
    std::cout << "\n========== NODES ==========\n";

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        std::cout << nodes[i].value << std::endl;

        for (size_t j = 0; j < nodes[i].losers.size(); ++j)
            printNode(nodes[i].losers[j], "",
                j == nodes[i].losers.size() - 1);

        std::cout << std::endl;
    }

    std::cout << "===========================\n";
}
// static bool nodeLess(const PmergeMe::Node& a, const PmergeMe::Node& b)
// {
//     return a.value < b.value;
// }

// static int jacobsthal(int k)
// {
//     if (k == 0)
//         return 0;
//     if (k == 1)
//         return 1;

//     int a = 0;
//     int b = 1;

//     for (int i = 2; i <= k; ++i)
//     {
//         int c = b + 2 * a;
//         a = b;
//         b = c;
//     }
//     return b;
// }

// static std::vector<size_t> getJacobsthalSequence(size_t size)
// {
//     std::vector<size_t> sequence;

//     if (size == 0)
//         return sequence;

//     sequence.push_back(0);

//     size_t previous = 1;
//     int k = 3;

//     while (previous < size)
//     {
//         size_t current = jacobsthal(k);

//         if (current > size)
//             current = size;

//         for (size_t i = current; i > previous; --i)
//             sequence.push_back(i - 1);

//         previous = current;
//         ++k;
//     }

//     return sequence;
// }

std::vector<PmergeMe::Node> PmergeMe::getWinner(std::vector<Node> &winners)
{
    std::vector<Node> noe;

    for (std::vector<Node>::iterator iter = winners.begin(); iter != winners.end(); iter += 2)
    {
        Node winner = *iter;
        Node loser = *(iter + 1);
        if (loser.value > winner.value)
            std::swap(winner, loser);
        winner.losers.push_back(loser);
        noe.push_back(winner);
    }
    return noe;
}
bool lowerBoundComp(const PmergeMe::Node &a, const PmergeMe::Node &b)
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

void PmergeMe::fordJohnson(std::vector<Node> &node)
{
    if (node.size() <= 1)
        return;
    bool drag = node.size() % 2 != 0;

    for (std::vector<Node>::iterator it = node.begin(); it != node.end() && (it + 1) != node.end();)
    {
        if (it->value < (it + 1)->value)
            std::swap(*it, *(it + 1));
        it->losers.push_back(*(it + 1));
        it = node.erase(it + 1);
    }

    Node dragNode = 0;
    if (drag)
    {
        dragNode = node.back();
        node.pop_back();
    }
    size_t sizeGeneration = node[0].losers.size();

    fordJohnson(node);

    std::vector<size_t> order = orderInsertiongenV(sizeGeneration);
    std::vector<Node>::iterator place;

    for (size_t orderixd = 0; orderixd < order.size(); orderixd++) 
    {
        int target = order[orderixd] - 1;
        for (size_t i = 0; i < node.size(); i++)
        {
            if (sizeGeneration != node[i].losers.size())
                continue;
            if (target == 0)
            {
                Node back = node[i].losers.back();
                place = std::lower_bound(node.begin(), node.begin() + i, back, lowerBoundComp);
                node.insert(place, back);
            }
            target--;
        }
        for (size_t i = 0; i < node.size(); i++)
        {
            if (node[i].losers.size() == sizeGeneration)
                node[i].losers.pop_back();
        }
    }
    if (drag)
    {
        place = std::lower_bound(node.begin(), node.end(), dragNode, lowerBoundComp);
        node.insert(place, dragNode);
    }
    printNodes(node);
}

void PmergeMe::start()
{
        // int oddn = -69;
        // std::vector<Node> nodes;
        // if (vect.size() % 2 != 0)
        // {
        //     oddn = vect.back();
        //     isOdd = true;
        // }
        // else
        //     isOdd = false;

        fordJohnson(node);
        printNodes(node);
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
        node.push_back(num);
    }
    start();
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


// void printNodeTree(std::ostream &os, const PmergeMe::Node &item, const std::string &prefix, bool isLast)
// {
//     os << prefix << (isLast ? "└── " : "├── ") 
//        << "\033[1;97mNode:\e[0m \033[1;32m" << item.value << "\e[0m\n";

//     std::size_t size = item.losers.size();
//     for (std::size_t i = 0; i < size; ++i)
//     {
//         bool lastLoser = (i == size - 1);
//         printNodeTree(os, item.losers[i], prefix + (isLast ? "    " : "│   "), lastLoser);
//     }
// }

// std::ostream &operator<<(std::ostream &os, const PmergeMe::Node &item)
// {
//     os << "\033[1;97mNode:\e[0m \033[1;32m" << item.value << "\e[0m\n";
    
//     std::size_t size = item.losers.size();
//     for (std::size_t i = 0; i < size; ++i)
//     {
//         printNodeTree(os, item.losers[i], "", (i == size - 1));
//     }
//     return os;
// }