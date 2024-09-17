/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:45:01 by mpitot            #+#    #+#             */
/*   Updated: 2024/09/17 11:08:24 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef HARL_HPP
# define HARL_HPP

class Harl
{
private:
	int		lvl;
	static const std::string	levels[];

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl(std::string level);
	void	complain(void);
	~Harl();
};

#endif