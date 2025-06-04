#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av)
{
    try
    {
        PmergeMe pmergeMe = PmergeMe(ac, av);

        std::cout << "Before: " << std::endl << pmergeMe << std::endl << std::endl;

        double vecTime = pmergeMe.sortVector();
        double deqTime = pmergeMe.sortDeque();

        std::cout << "After: " << std::endl << pmergeMe << std::endl << std::endl;

        std::cout << "Time to process a std::vector of " << pmergeMe.getVector().size() << " elements : " << vecTime << "us" << std::endl;
        std::cout << "Time to process a std::deque of  " << pmergeMe.getDeque().size() << " elements : " << deqTime << "us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}