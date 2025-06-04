#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	try
	{
		std::vector<int> vec;
		std::list<int> lst;

		{
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(42);
			vec.push_back(5);

			lst.push_back(10);
			lst.push_back(20);
			lst.push_back(30);
			lst.push_back(40);
		} // filling the containers

		std::cout << "Found in vector: " << *easyfind(vec, 42) << std::endl;
		std::cout << "Found in list: " << *easyfind(lst, 30) << std::endl;

		// This will throw
		std::cout << "Trying to find 99 in vector..." << std::endl;
		std::cout << *easyfind(vec, 99) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
