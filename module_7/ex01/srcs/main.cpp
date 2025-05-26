#include "iter.hpp"
#include <iostream>

template <typename T>
void	printArray(const T* array, size_t length)
{
	std::cout << "[";
	for (size_t i = 0; i < length; i++)
	{
		if (i == 0)
			std::cout << array[i];
		else
			std::cout << ", " << array[i];
	}
	std::cout << "]" << std::endl;
}

void	modulo2(int &n)
{
	n = n % 2;
}

void	upperChar(char &c)
{
	c = toupper(c);
}

void printElement(const std::string &elem)
{
	std::cout << elem << " ";
}

int main(void)
{
	{
		int test[3] = {1, 2, 3};

		std::cout << "Array before modulo 2" << std::endl;
		printArray(test, 3);
		iter<int>(test, 3, &modulo2);
		std::cout << "Array after modulo 2" << std::endl;
		printArray(test, 3);
	}
	std::cout << std::endl;
	{
		char test[5] = {'H', 'e', 'l', 'l', 'o'};

		std::cout << "Array before upperChar" << std::endl;
		printArray(test, 5);
		iter<char>(test, 5, &upperChar);
		std::cout << "Array after upperChar" << std::endl;
		printArray(test, 5);

	}
	std::cout << std::endl;
	{
		const std::string test[3] = {"Hello", "from", "const"};

		std::cout << "Printing const array using iter:" << std::endl;
		iter<std::string>(test, 3, &printElement);
		std::cout << std::endl;
	}
	return (0);
}
