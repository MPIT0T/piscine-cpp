#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define DATAFILE std::string("data.csv")

#include <string>
#include <map>

typedef std::map<std::string, float> map_t;

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();

    const std::map<std::string, float> &getTable() const;
    const float &getExchangeRate(const std::string &date) const;
    float checkDateValue(const std::string &date, const std::string &value) const;
    void printLine(const std::string &line, const std::string &sep) const;
    std::string findSeparator(const std::string &line) const;

    void printExchanges(const std::string &inputFileName) const;

private:
    map_t _table;
};

std::ostream &operator<<(std::ostream &OUT, const BitcoinExchange &exchange);

#endif
