#include "ScalarConverter.h"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &){ return (*this);};
ScalarConverter::~ScalarConverter(){};

int Check_float_double_literals(const std::string& value)
{
    if (value.empty()) 
    {
        std::cout << "You need to provide a valid value." << std::endl;
        return(0);
    }
    std::string float_literals[3] = { "-inff", "+inff", "nanf" };
    std::string double_literals[3] = { "-inf", "+inf", "nan" };

    for (int i = 0; i < 3; i++)
    {
        if (value == float_literals[i])
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << value << std::endl;
            std::cout << "double: " << value.substr(0, value.length() - 1) << std::endl;
            return (0);
        }
        if (value == double_literals[i])
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << value << "f" << std::endl;
            std::cout << "double: " << value << std::endl;
            return(0);
        }
    }
    return (1);
}

void ConvertToChar(double dnum)
{
    if (dnum < 0 || dnum > 127)
        std::cout << "char: impossible" << std::endl;
    else if (dnum < 32 || dnum > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(dnum) << "'" << std::endl;
}

void ConvertToInt(double dnum)
{
    if (dnum < INT_MIN || dnum > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(dnum) << std::endl;
}

void ConvertToFloat(double dnum)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(dnum) << "f" << std::endl;
}

void ConvertToDouble(double dnum)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << dnum << std::endl;
}

void ScalarConverter::convert(const std::string& value)
{
    if (!Check_float_double_literals(value))
        return ;

    if (value.length() == 1 && !isdigit(value[0]))
    {
        int ascii = static_cast<int>(value[0]);
        if (ascii < 32 || ascii > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << value[0] << "'" << std::endl;
        std::cout << "int: " << ascii << std::endl;
        std::cout << "float: " << static_cast<float>(ascii) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(ascii) << ".0" << std::endl;
        return;
    }
    std::string remove_f = value; //handle case 42.0f (strtod do not understand the f in the end)
    if (value[value.length() - 1] == 'f')
        remove_f = value.substr(0, value.length() - 1);

    char *end_pointer;
    double dnum = std::strtod(remove_f.c_str(), &end_pointer);

    if (*end_pointer != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    ConvertToChar(dnum);
    ConvertToInt(dnum);
    ConvertToFloat(dnum);
    ConvertToDouble(dnum);
}