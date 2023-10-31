#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>


class BitcoinExchange
{
    private:

    std::string data_string;
    float data_float;
    std::string input_string;
    float input_float;
    std::map<std::string, float> bitcoinData;

    bool checkValue(std::string str, int max, int i);
    bool checkDate(std::string str, int i);
    void printResults();

    public:

    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &rhs);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange(void);
    void checkData(char **argv);
};