/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:44:04 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/13 22:43:37 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

void	printArray(Array<int>& array)
{
	std::cout << "[";
	for (unsigned int i = 0; i < array.size(); i++)
	{
		if (i == 0)
			std::cout << array[i];
		else
			std::cout << ", " << array[i];
	}
	std::cout << "]" << std::endl;
}

void	printArray(Array<char>& array)
{
	std::cout << "[";
	for (unsigned int i = 0; i < array.size(); i++)
	{
		if (i == 0)
			std::cout << array[i];
		else
			std::cout << ", " << array[i];
	}
	std::cout << "]" << std::endl;
}

int main()
{
	std::cout << "===== Integer Array Test =====" << std::endl;
	Array<int> intArray(5);
	for (int i = 0; i < 5; i++)
		intArray[i] = i;
	std::cout << "Original intArray (size: " << intArray.size() << "): ";
	printArray(intArray);

	Array<int> intCopy;
	std::cout << "Empty intCopy (size: " << intCopy.size() << "): ";
	printArray(intCopy);

	intCopy = intArray;
	intArray[0] = 100;

	std::cout << "After assignment and modification:" << std::endl;
	std::cout << "intCopy: ";
	printArray(intCopy);
	std::cout << "intArray: ";
	printArray(intArray);

	try
	{
		std::cout << "Access intArray[0]: " << intArray[0] << std::endl;
		std::cout << "Access intArray[5] (out of bounds): ";
		std::cout << intArray[5] << std::endl; // Should throw
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}


	std::cout << "\n===== Char Array Test =====" << std::endl;
	Array<char> charArray(26);
	for (int i = 0; i < 26; i++)
		charArray[i] = 'a' + i;
	std::cout << "Original charArray (size: " << charArray.size() << "): ";
	printArray(charArray);

	Array<char> charCopy;
	std::cout << "Empty charCopy (size: " << charCopy.size() << "): ";
	printArray(charCopy);

	charCopy = charArray;
	charArray[0] = 'Z';

	std::cout << "After assignment and modification:" << std::endl;
	std::cout << "charCopy: ";
	printArray(charCopy);
	std::cout << "charArray: ";
	printArray(charArray);

	try
	{
		std::cout << "Access charArray[0]: " << charArray[0] << std::endl;
		std::cout << "Access charArray[27] (out of bounds): ";
		std::cout << charArray[27] << std::endl; // Should throw
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}


	std::cout << "\n===== Const Array Test =====" << std::endl;
	Array<int> constSource(3);
	for (int i = 0; i < 3; ++i)
		constSource[i] = i * 10;

	const Array<int> constArray = constSource;

	std::cout << "constArray contents: ";
	for (unsigned int i = 0; i < constArray.size(); ++i)
		std::cout << constArray[i] << " ";
	std::cout << std::endl;

	try
	{
		std::cout << "Access constArray[3] (out of bounds): ";
		std::cout << constArray[3] << std::endl; // Should throw
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}

