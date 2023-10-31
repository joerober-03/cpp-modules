#pragma once

#include <iostream>

class ScalarConverter
{
    private:

    static char    _char;
    static int     _int;
    static float   _float;
    static double  _double;
    static int     _charErr;
    static int     _intErr;
    static int     _floatErr;
    static int     _doubleErr;

    ScalarConverter();
    ScalarConverter(const ScalarConverter &rhs);
    ScalarConverter &operator=(const ScalarConverter &rhs);
    ~ScalarConverter();

    public:


    static void    convert(const std::string input);
    static void    displayValues(const std::string input);

    static void    fromChar(const std::string input);
    static void    fromInt(const std::string input);
    static void    fromFloat(const std::string input);
    static void    fromDouble(const std::string input);

    static bool    isConvertible(const std::string string, int n);

    class InvalidInput : public std::exception
    {
        public:

        virtual const char* what() const throw();
    };
};