#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
    *this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    this->bitcoinData = rhs.bitcoinData;
    this->data_float = rhs.data_float;
    this->data_string = rhs.data_string;
    this->input_float = rhs.input_float;
    this->input_string = rhs.input_string;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void    BitcoinExchange::printResults()
{
    std::map<std::string, float>::const_iterator iter;
    float res;

    res = 0;
    iter = bitcoinData.find(this->input_string);
    if (iter != bitcoinData.end())
        res = (iter->second) * this->input_float;
    else
    {
        iter = bitcoinData.upper_bound(this->input_string);
        if (iter == bitcoinData.begin())
        {
            res = (iter->second) * this->input_float;
        }
        else
        {
            iter = bitcoinData.lower_bound(this->input_string);
            iter--;
            res = (iter->second) * this->input_float;
        }
    }
    std::cout << this->input_string << " => " << this->input_float << " = " << res << std::endl;
}

bool    BitcoinExchange::checkDate(std::string str, int i)
{
    if (str.length() != 10)
        return (false);
    std::string date;
    std::istringstream iss(str);
    int year, month, day;
    std::getline(iss, date, '-');
    for (int i = 0; i < static_cast<int>(date.length()); i++)
    {
        if (isdigit(date[i]) == 0)
            return (false);
    }
    std::istringstream(date) >> year;
    if (year < 1000 || year > 9999)
        return (false);
    std::getline(iss, date, '-');
    for (int i = 0; i < static_cast<int>(date.length()); i++)
    {
        if (isdigit(date[i]) == 0)
            return (false);
    }
    std::istringstream(date) >> month;
    if (month < 1 || month > 12)
        return (false);
    std::getline(iss, date, '-');
    for (int i = 0; i < static_cast<int>(date.length()); i++)
    {
        if (isdigit(date[i]) == 0)
            return (false);
    }
    std::istringstream(date) >> day;
    if (day < 1 || day > 31)
        return (false);
    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
        return (false);
    if (year % 4 != 0 && month == 2 && day > 28)
        return (false);
    if (year % 4 == 0 && month == 2 && day > 29)
        return (false);
    if (i == 1)
        this->data_string = str;
    else
        this->input_string = str;
    return (true);
}

bool    BitcoinExchange::checkValue(std::string str, int max, int i)
{
    int fnum = 0;
    int dotnum = 0;
    int dashnum = 0;
    float value;
    if (str.empty())
    {
        std::cerr << "Error: no value after date." << std::endl;
        return (false);
    }
    for (unsigned long i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == 0)
        {
            if (str[i] == 'f' && i == (str.length() - 1) && fnum == 0)
                fnum = 1;
            else if (str[i] == '.' && i != 0 && i != (str.length() - 1) && dotnum == 0)
                dotnum = 1;
            else if (str[i] == '-' && i == 0 && dashnum == 0)
                dashnum = 1;
            else
            {
                std::cerr << "Error: invalid character in value." << std::endl;
                return (false);
            }
        }
    }
    try
    {
        value = stof(str);
    }
    catch(...)
    {
        std::cerr << "Error: out of range argument." << std::endl;
        return (false);
    }
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    if (value > max)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }
    if (i == 1)
        this->data_float = value;
    else
        this->input_float = value;
    return (true);
}

void    BitcoinExchange::checkData(char **argv)
{
    std::ifstream infile, infile2;
    std::string input;
    int index;
    infile.open("data.csv");
    infile2.open(argv[1]);
    if (infile.fail())
    {
        std::cerr << "Error: could not open data.csv." << std::endl;
        exit(1);
    }
    if (infile2.fail())
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    while (getline(infile, input))
    {
        if (!input.empty())
        {
            if (input != "date,exchange_rate")
            {
                std::cout << "Error: no \"date,exchange_rate\" in input file." << std::endl;
                exit(5);
            }
            else
                break ;
        }
    }
    while (getline(infile, input))
    {
        index = input.find(',');
        if (index == -1 || index != 10)
        {
            std::cerr << "Error: bad input => " << input << std::endl;
            exit(2);
        }
        if (checkDate(input.substr(0, index), 1) == false)
        {
            std::cerr << "Error: invalid csv date." << std::endl;
            exit(3);
        };
        if (checkValue(input.substr(11), INT_MAX, 1) == false)
        {
            exit(4);
        }
        this->bitcoinData.insert(std::make_pair(this->data_string, this->data_float));
    }
    while (getline(infile2, input))
    {
        if (!input.empty())
        {
            if (input != "date | value")
                std::cout << "Error: no \"date | value\" in input file." << std::endl;
            break ;
        }
    }
    while (getline(infile2, input))
    {
        int error = 1;  
        error = 0;
        index = input.find('|');
        if (index == -1)
        {
            std::cerr << "Error: bad input => " << input << std::endl;
            error = 1;
        }
        else
        {
            if (input[12] && (input[10] != ' ' || input[11] != '|' || input[12] != ' '))
            {
                std::cerr << "Error: bad input => " << input << std::endl;
                error = 1;
            }
            else
            {
                if (checkDate(input.substr(0, index - 1), 0) == false)
                {
                    std::cerr << "Error: invalid date => " << input.substr(0, index - 1) << std::endl;
                    error = 1;
                }
                if (checkValue(input.substr(13), 1000, 0) == false)
                {
                    //std::cerr << "input value error !" << std::endl;
                    error = 1;
                }
            }
        }
        if (error == 0)
        {
            printResults();
        }
    }
    infile.close();
    infile2.close();
}