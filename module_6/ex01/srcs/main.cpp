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

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data		data = {42};
	uintptr_t	rawData = Serializer::serialize(&data);

	std::cout << "Address: " << &data << std::endl << "Content: " << data.num << std::endl << std::endl;
	std::cout << "Serialized: " << rawData << std::endl << std::endl;

	Data *newData = Serializer::deserialize(rawData);

	std::cout << "Address: " << newData << std::endl << "Content: " << newData->num << std::endl << std::endl;

	return (0);
}
