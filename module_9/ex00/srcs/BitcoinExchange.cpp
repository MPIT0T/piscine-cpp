#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file(DATAFILE.c_str());
    if (!file)
        throw std::runtime_error("Error opening file \"" + DATAFILE + "\"");

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string key, value;
        std::getline(ss, key, ',');
        std::getline(ss, value);
        _table[key] = std::atof(value.c_str());
    }

    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        map_t::const_iterator it = src.getTable().begin();
        while (it != src.getTable().end())
        {
            _table[it->first] = it->second;
            ++it;
        }
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const map_t &BitcoinExchange::getTable() const
{
    return _table;
}

const float &BitcoinExchange::getExchangeRate(const std::string &date) const
{
    map_t::const_iterator it = _table.find(date);
    if (it != _table.end())
        return it->second;
    it = _table.lower_bound(date);
    if (it != _table.begin())
        return (--it)->second;
    throw std::runtime_error("date \"" + date + "\" is lower than the first date in database");
}

float BitcoinExchange::checkDateValue(const std::string &date, const std::string &value) const
{
    if (date.find(' ') != std::string::npos || value.find(' ') != std::string::npos )
        throw std::runtime_error("extra space found");

    ssize_t year, month, day;
    char sep1, sep2;

    std::istringstream iss(date);
    if (!(iss >> year >> sep1 >> month >> sep2 >> day))
        throw std::runtime_error("wrong date format");

    if (sep1 != '-' || sep2 != '-')
        throw std::runtime_error("date separator must be '-'");

    if (month < 1 || month > 12)
        throw std::runtime_error("month is out of range");

    const int daysInMonth[] = { 31, year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day < 1 || day > daysInMonth[month - 1])
        throw std::runtime_error("day is out of range");

    const float fValue = std::atof(value.c_str());

    if (fValue < 0)
        throw std::runtime_error("not a positive number");
    if (fValue > 1000)
        throw std::runtime_error("too large number");

    return fValue;
}

void BitcoinExchange::printLine(const std::string &line) const
{
    std::string::size_type pipePos = line.find(" | ");
    if (pipePos == std::string::npos)
        throw std::runtime_error("invalid line");

    const std::string date = line.substr(0, pipePos);
    const std::string value = line.substr(pipePos + 3);

    std::cout << date << " => " << value << " = " << checkDateValue(date, value) * getExchangeRate(date) << std::endl;
}

void BitcoinExchange::printExchanges(const std::string &inputFileName) const
{
    std::ifstream file(inputFileName.c_str());
    if (!file)
        throw std::runtime_error("Error opening file \"" + inputFileName + "\"");

    std::string line;
    while (std::getline(file, line))
    {
        try
        {
            printLine(line);
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            continue ;
        }
    }
}

std::ostream & operator<<(std::ostream &os, const BitcoinExchange &exchange)
{
    for (map_t::const_iterator it = exchange.getTable().begin(); it != exchange.getTable().end(); ++it)
    {
        if (it != exchange.getTable().begin())
            os << std::endl;
        os << it->first << "," << it->second;
    }
    return os;
}
