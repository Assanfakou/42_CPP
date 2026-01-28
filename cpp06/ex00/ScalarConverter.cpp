#include "ScalarConverter.h"
#include <limits>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
        (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
        (void)other;
        return (*this);
}

bool psudoLeterals(const std::string& let)
{
        return (let == "nan") || (let == "-inf") || (let == "+inf")
        || (let == "+inff") || (let == "-inff") || (let == "nanf");
}

std::string pseudoStringf(const std::string& let)
{
    if (let == "nan" || let == "nanf")
        return "nanf";
    if (let == "+inf" || let == "+inff")
        return "+inff";
    if (let == "-inf" || let == "-inff")
        return "-inff";
    return "null";
}

std::string pseudoStringd(const std::string& let)
{
    if (let == "nan" || let == "nanf")
        return "nan";
    if (let == "+inf" || let == "+inff")
        return "+inf";
    if (let == "-inf" || let == "-inff")
        return "-inf";
    return "null";
}

void ScalarConverter::convert(const std::string& inp)
{
        double val;
        bool isChar = false;

        if (inp.length() == 1 && !std::isdigit(inp[0]))
        {
                val = static_cast<double>(inp[0]);
                isChar = true;
        }
        else
                val = std::strtod(inp.c_str(), NULL);

        std::cout << "Char : ";

        if (psudoLeterals(inp) || val < std::numeric_limits<char>::min()
                || val > std::numeric_limits<char>::max())
                std::cout << "Imposible\n";
        else if (!std::isprint(static_cast<char>(val)))
                std::cout << "Not Printable\n";
        else
                std::cout << "'" << static_cast<char>(val) << "'\n";

        std::cout << "Int : ";

        if (psudoLeterals(inp) || val < std::numeric_limits<int>::min()
                || val > std::numeric_limits<int>::max()) 
                std::cout << " Imposible\n";
        else
                std::cout << static_cast<int>(val) << "\n";

        std::cout << "Float : ";

        if (psudoLeterals(inp))
                std::cout << pseudoStringf(inp) << "\n";
        else
        {
                std::cout << static_cast<float>(val);

                float tmp = static_cast<float>(val);
                if (tmp == static_cast<int>(val))
                        std::cout << ".0f";
                std::cout << "\n";
        }

        std::cout << "Double : ";
        if (psudoLeterals(inp))
                std::cout << pseudoStringd(inp) << "\n";
        else
        {
                std::cout << static_cast<double>(val);

                if (val == static_cast<int>(val))
                        std::cout << ".0";
                std::cout << "\n";
        }
}
ScalarConverter::~ScalarConverter() {}
