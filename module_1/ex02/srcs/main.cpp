/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:05:12 by mpitot            #+#    #+#             */
/*   Updated: 2024/06/21 16:25:45 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_content(std::string str, std::string *stringPTR, std::string &stringREF)
{

}

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address:" << std::endl
			  << &str << std::endl
			  << &stringPTR << std::endl
			  << &stringREF << std::endl
			  << std::endl;

	std::cout << "Values:" << std::endl
			  << str << std::endl
			  << *stringPTR << std::endl
			  << stringREF << std::endl
			  << std::endl;

	return (0);
}
