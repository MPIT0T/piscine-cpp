#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage : ./btc [input.txt]" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange bitcoinExchange = BitcoinExchange();

        bitcoinExchange.printExchanges(av[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
