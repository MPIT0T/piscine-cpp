/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:24:58 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/07 16:40:12 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string _ideas[100];

public:
/* Constructors and destructors */
	Brain();
	Brain(const Brain &copy);
	~Brain();

/* Operator overloads */
	Brain	&operator=(const Brain &src);

/* Member functions */
	void	addIdea(const std::string& idea);
	void	setIdea(int index, const std::string& idea);
	void	displayIdeas() const;
};

#endif