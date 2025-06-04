#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    // Test 1: Subject test
    {
        std::cout << "--- Subject Test ---" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Expected: 14
    }

    // Test 2: Exception on overfill
    {
        std::cout << "\n--- Overfill Test ---" << std::endl;
        Span sp(2);
        try
        {
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3); // should throw
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    // Test 3: Exception with < 2 numbers
    {
        std::cout << "\n--- Too Few Elements Test ---" << std::endl;
        Span sp(3);
        sp.addNumber(42);
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    // Test 4: Large scale (10,000+ random numbers)
    {
        std::cout << "\n--- Large Scale Test ---" << std::endl;
        Span sp(10000);
        std::srand(static_cast<unsigned int>(std::time(0)));

        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test 5: Fill using iterators
    {
        std::cout << "\n--- Range Fill Test ---" << std::endl;
        std::vector<int> vec;
        for (int i = 0; i < 100; ++i)
            vec.push_back(i * 10);

        Span sp(100);
        sp.addNumber(vec.begin(), vec.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Expected: 10
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Expected: 990
    }

    return 0;
}
