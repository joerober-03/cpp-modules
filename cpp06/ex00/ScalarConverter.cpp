#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
    *this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return(*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;
int ScalarConverter::_charErr = 0;
int ScalarConverter::_intErr = 0;
int ScalarConverter::_floatErr = 0;
int ScalarConverter::_doubleErr = 0;

void    ScalarConverter::convert(const std::string input)
{
    if (input.compare("nan") == 0 || input.compare("nanf") == 0)
    {
        _charErr = 2;
        _intErr = 1;
        _floatErr = 2;
        _doubleErr = 2;
        displayValues(input);
    }
    else if (input.compare("+inf") == 0 || input.compare("-inf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0)
    {
        _charErr = 2;
        _intErr = 1;
        _floatErr = 3;
        _doubleErr = 3;
        displayValues(input);
    }
    else if ((input[0] >= 0 && input[0] < 32) || input[0] == 127)
    {
        _charErr = 1;
        fromChar(input);
    }
    else if ((input[0] > 47 && input[0] < 58) || (input[0] == '-' && input[1] > 47 && input[1] < 58))
    {
        int i = 0;
        int isdot = 0;
        while (input[i] != 0)
        {
            if (input[i] == '.')
            {
                if (isdot == 1 || (input[i + 1] == 0))
                {
                    _charErr = 2;
                    _doubleErr = 1;
                    _floatErr = 1;
                    _intErr = 1;
                    displayValues(input);
                    throw (ScalarConverter::InvalidInput());
                }
                isdot = 1;
            }
            else if (input[i] == 'f')
                ;
            else if (input[i] < 47 || input[i] > 58)
                if (input[i] != '-')
                {
                    _charErr = 2;
                    _doubleErr = 1;
                    _floatErr = 1;
                    _intErr = 1;
                    displayValues(input);
                    throw (ScalarConverter::InvalidInput());
                }
            i++;
        }
        if (isdot == 0)
            fromInt(input);
        else
        {
            int l = input.length();
            l--;
            if (input[l] == 'f')
                fromFloat(input);
            else
                fromDouble(input);
        }
    }
    else if ((input[0] > 31 && input[0] < 48) || (input[0] > 57 && input[0] < 127))
    {
        if (input.length() > 1)
        {
            _charErr = 2;
            _doubleErr = 1;
            _floatErr = 1;
            _intErr = 1;
            displayValues(input);
            throw (ScalarConverter::InvalidInput());
        }
        else
        {
            fromChar(input);
        }
    }
    else
        throw (ScalarConverter::InvalidInput());
}

void    ScalarConverter::fromChar(const std::string input)
{
    _char = input[0];
    _int = static_cast<int>(_char);
    _float = static_cast<float>(_char);
    _double = static_cast<double>(_char);
    displayValues(input);
}

void    ScalarConverter::fromInt(const std::string input)
{
    if (isConvertible(input, 1) == false)
        _intErr = 1;
    else
        _int = std::stoi(input);
    _char = static_cast<char>(_int);
    _float = static_cast<float>(_int);
    _double = static_cast<double>(_int);
    if ((_int >= 0 && _int < 32) || _int == 127)
        _charErr = 1;
    else if (_int < 0 || _int > 127)
        _charErr = 2;
    displayValues(input);
}

void    ScalarConverter::fromFloat(const std::string input)
{
    if (isConvertible(input, 2) == false)
        _floatErr = 1;
    else
        _float = std::stof(input);
    _char = static_cast<char>(_float);
    if (_float > 2147483647 || _float < -2147483648)
        _intErr = 1;
    else
        _int = static_cast<int>(_float);
    _double = static_cast<double>(_float);
    if ((_int >= 0 && _int < 32) || _int == 127)
        _charErr = 1;
    else if (_int < 0 || _int > 127)
        _charErr = 2;
    displayValues(input);
}

void    ScalarConverter::fromDouble(const std::string input)
{
    if (isConvertible(input, 3) == false)
        _doubleErr = 1;
    else
        _double = std::stod(input);
    _char = static_cast<char>(_double);
    if (_double > 2147483647 || _double < -2147483648)
        _intErr = 1;
    else
        _int = static_cast<int>(_double);
    _float = static_cast<float>(_double);
    if ((_int >= 0 && _int < 32) || _int == 127)
        _charErr = 1;
    else if (_int < 0 || _int > 127)
        _charErr = 2;
    displayValues(input);
}

void    ScalarConverter::displayValues(const std::string input)
{
    if (_charErr == 0)
        std::cout << "char: " << _char << std::endl;
    else if (_charErr == 1)
        std::cout << "char: Non displayable" << std::endl;
    else if (_charErr == 2)
        std::cout << "char: impossible" << std::endl;
    if (_intErr == 0)
        std::cout << "int: " << _int << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (_floatErr == 0)
    {
        std::cout << "float: " << _float;
        if (_float - _int == 0)
            std::cout << ".0f";
        else
            std::cout << "f";
        std::cout << std::endl;
    }
    else if (_floatErr == 1)
        std::cout << "float: impossible" << std::endl;
    else if (_floatErr == 2)
        std::cout << "float: nanf" << std::endl;
    else if (_floatErr == 3)
    {
        if (input[0] == '+')
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    if (_doubleErr == 0)
    {
        std::cout << "double: " << _double;
        if (_double - _int == 0)
            std::cout << ".0";
        std::cout << std::endl;
    }
    else if (_doubleErr == 1)
        std::cout << "double: impossible" << std::endl;
    else if (_doubleErr == 2)
        std::cout << "double: nan" << std::endl;
    else if (_doubleErr == 3)
    {
        if (input[0] == '+')
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
}

bool    ScalarConverter::isConvertible(const std::string string, int n)
{
    bool result = false;
    if (n == 1)
    {
        try
        {
            std::stoi(string);
            result = true;
        }
        catch(...)
        {
        }
    }
    if (n == 2)
    {
        try
        {
            std::stof(string);
            result = true;
        }
        catch(...)
        {
        }
    }
    if (n == 3)
    {
        try
        {
            std::stod(string);
            result = true;
        }
        catch(...)
        {
        }
    }

    return (result);
}

const char* ScalarConverter::InvalidInput::what(void) const throw()
{
    return ("invalid input");
}