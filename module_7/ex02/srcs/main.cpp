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
	{
		Array<int> a(5);

		for (int i = 0; i < 5; i++)
			a[i] = i;
		std::cout << a.size() << std::endl;
		printArray(a);
		Array<int> b;
		std::cout << b.size() << std::endl;
		printArray(b);
		b = a;
		a[0] = 100;
		printArray(b);
		printArray(a);
		try
		{
			std::cout << a[0] << std::endl;
			std::cout << a[5] << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Array<char> a(26);

		int i = 0;
		for (char c = 'a'; c <= 'z'; c++)
		{
			a[i] = c;
			i++;
		}
		std::cout << a.size() << std::endl;
		printArray(a);
		Array<char> b;
		std::cout << b.size() << std::endl;
		printArray(b);
		b = a;
		a[0] = 'Z';
		printArray(b);
		printArray(a);
		try
		{
			std::cout << a[0] << std::endl;
			std::cout << a[27] << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
