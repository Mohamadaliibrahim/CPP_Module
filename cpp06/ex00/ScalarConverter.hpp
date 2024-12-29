#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);

        enum eType
        {
            TYPE_CHAR,
            TYPE_INT,
            TYPE_FLOAT,
            TYPE_DOUBLE,
            TYPE_INVALID
        };
        static eType detectType(const std::string &literal);
        static void printChar(double value, bool impossible);
        static void printInt(double value, bool impossible);
        static void printFloat(double value, bool impossible, bool isPseudo);
        static void printDouble(double value, bool impossible, bool isPseudo);
        static bool isPseudoFloat(const std::string &literal);
        static bool isPseudoDouble(const std::string &literal);

    public:
        static  void convert(const std::string &literal);
        ~ScalarConverter();
};

#endif