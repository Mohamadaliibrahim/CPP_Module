#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{

}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::eType ScalarConverter::detectType(const std::string &literal)
{
    if (literal.size() == 3 && literal[0] == '\'' && literal[literal.size() - 1] == '\'')
        return TYPE_CHAR;
    if (isPseudoFloat(literal))
        return TYPE_FLOAT;
    if (isPseudoDouble(literal))
        return TYPE_DOUBLE;
    if (literal.size() > 1 && literal[literal.size() - 1] == 'f')
    {
        std::string possibleDouble = literal.substr(0, literal.size() - 1);
        char *endptr = NULL;
        std::strtod(possibleDouble.c_str(), &endptr);
        if (*endptr == '\0')
            return TYPE_FLOAT;
    }
    {
        char *endptr = NULL;
        std::strtod(literal.c_str(), &endptr);
        if (*endptr == '\0')
            return TYPE_DOUBLE;
    }

    return TYPE_INVALID;
}

bool ScalarConverter::isPseudoFloat(const std::string &literal)
{
    return (literal == "+inff" || literal == "-inff" || literal == "nanf");
}

bool ScalarConverter::isPseudoDouble(const std::string &literal)
{
    return (literal == "+inf" || literal == "-inf" || literal == "nan");
}

// isnan check if the input is a number...
// isinf check if the input is a infinte...
// isprint check if the input is printable ASCII or not..

void ScalarConverter::printChar(double value, bool impossible)
{
    std::cout << "char: ";
    if (impossible)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (value < std::numeric_limits<char>::min() || 
        value > std::numeric_limits<char>::max() ||
        std::isnan(value) || std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value, bool impossible)
{
    std::cout << "int: ";
    if (impossible)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (value < static_cast<double>(std::numeric_limits<int>::min()) ||
        value > static_cast<double>(std::numeric_limits<int>::max()) ||
        std::isnan(value) || std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(value);
    std::cout << i << std::endl;
}

void ScalarConverter::printFloat(double value, bool impossible, bool isPseudo)
{
    std::cout << "float: ";
    if (impossible)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (isPseudo)
    {
        if (value != value)
            std::cout << "nanf" << std::endl;
        else if (value > 0 && std::isinf(value))
            std::cout << "+inff" << std::endl;
        else if (value < 0 && std::isinf(value))
            std::cout << "-inff" << std::endl;
        return;
    }
    float f = static_cast<float>(value);
    std::cout << f;
    if (f - static_cast<int>(f) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value, bool impossible, bool isPseudo)
{
    std::cout << "double: ";
    if (impossible)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (isPseudo)
    {
        if (value != value)
            std::cout << "nan" << std::endl;
        else if (value > 0 && std::isinf(value))
            std::cout << "+inf" << std::endl;
        else if (value < 0 && std::isinf(value))
            std::cout << "-inf" << std::endl;
        return;
    }
    std::cout << value;
    if (value - static_cast<int>(value) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    eType type = detectType(literal);

    if (type == TYPE_CHAR)
    {
        char c = literal[1];
        double value = static_cast<double>(c);
        printChar(value, false);
        printInt(value, false);
        printFloat(value, false, false);
        printDouble(value, false, false);
        return;
    }
    if (type == TYPE_FLOAT && isPseudoFloat(literal))
    {
        double value;
        if (literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::numeric_limits<double>::quiet_NaN();
        printChar(value, true);
        printInt(value, true);
        printFloat(value, false, true);
        printDouble(value, false, true);
        return;
    }
    if (type == TYPE_DOUBLE && isPseudoDouble(literal))
    {
        double value;
        if (literal == "+inf")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::numeric_limits<double>::quiet_NaN();

        printChar(value, true);
        printInt(value, true);
        printFloat(value, false, true);
        printDouble(value, false, true);
        return;
    }
    // strtof function transform the string to float way...
    if (type == TYPE_FLOAT)
    {
        std::string tmp = literal.substr(0, literal.size() - 1);
        double value = std::strtod(tmp.c_str(), NULL);
        printChar(value, false);
        printInt(value, false);
        printFloat(value, false, false);
        printDouble(value, false, false);
        return;
    }
    // strtod function transform the string to double way...
    else if (type == TYPE_DOUBLE)
    {
        double value = std::strtod(literal.c_str(), NULL);
        printChar(value, false);
        printInt(value, false);
        printFloat(value, false, false);
        printDouble(value, false, false);
        return;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
