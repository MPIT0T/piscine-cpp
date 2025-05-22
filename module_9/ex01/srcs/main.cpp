#include "RPN.hpp"
#include <iostream>
#include <string>

void removeBlanks(std::string &input)
{
    std::string result;
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        if (!std::isspace(static_cast<unsigned char>(*it)))
            result += *it;
    }
    input = result;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN \"operations\"";
        return 1;
    }

    std::string operations = av[1];
    removeBlanks(operations);
    try
    {
        RPN rpn;
        for (size_t i = 0; i < operations.size(); ++i)
            rpn.pushToken(operations[i]);
        std::cout << rpn.getResult() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;
}
