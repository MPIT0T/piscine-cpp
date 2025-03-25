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

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stack>

int main()
{
	std::vector<int> vector;
	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);

	std::cout << easyfind(vector, 3) << std::endl;
	std::cout << easyfind(vector, 6) << std::endl;

	std::stack<int> stack;
	stack.push(0);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	std::cout << easyfind(stack, 3) << std::endl;
	std::cout << easyfind(stack, 6) << std::endl;

	std::list<int> list;
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	std::cout << easyfind(list, 3) << std::endl;
	std::cout << easyfind(list, 6) << std::endl;
}
