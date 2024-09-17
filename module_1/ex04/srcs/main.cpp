/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:05:12 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/16 14:59:09 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	open_files(std::ifstream &in, std::ofstream &out, std::string file)
{
	in.open(file.c_str(), std::ios::in);
	if (!in.is_open())
	{
		std::cerr << "Error: Can't open file " << file << std::endl;
		return (1);
	}
	std::string out_file = std::string(file) + ".replace";
	out.open(out_file.c_str(), std::ios::out);
	if (!out.is_open())
	{
		std::cerr << "Error: Can't create file " << out_file << std::endl;
		in.close();
		return (1);
	}
	return (0);
}

void	replace(std::ifstream &in, std::ofstream &out, std::string search, std::string replace)
{
	std::string buffer;
	size_t		pos;

	std::getline(in, buffer, '\0');
	pos = buffer.find(search, 0);
	while (pos != std::string::npos)
	{
		buffer.erase(pos, search.length());
		buffer.insert(pos, replace);
		pos = buffer.find(search, pos + replace.length());
	}
	if (buffer.length() != 0)
		out <<  buffer;
}


int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " [FILE] [SEARCH_STRING] [REPLACE_STRING]" << std::endl;
		return (1);
	}
	if (!*av[2])
	{
		std::cerr << "Error: Empty search string" << std::endl;
		return (1);
	}

	std::ifstream in;
	std::ofstream out;

	if (open_files(in, out, av[1]))
		return (1);
	replace(in, out, av[2], av[3]);
	return 0;
}
