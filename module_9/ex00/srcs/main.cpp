#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage : ./btc [input.txt]" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange bitcoinExchange = BitcoinExchange();

        bitcoinExchange.printExchanges(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
