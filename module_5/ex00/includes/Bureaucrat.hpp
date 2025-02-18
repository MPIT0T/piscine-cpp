/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:30:38 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/15 15:05:09 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

	Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &copy);

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);

	~Bureaucrat();

	const std::string	&getName() const;
	const int			&getGrade() const;

	void				setGrade(int grade);
	void				incrementGrade();
	void				decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream OUT, const Bureaucrat &bureaucrat);

#endif