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

# include <Form.hpp>
# include <string>
# include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
/* Constructors */
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);

	~Bureaucrat();

/* Operators */
	Bureaucrat &operator=(const Bureaucrat &copy);

/* Getters */
	const std::string	&getName() const;
	const int			&getGrade() const;

/* Setters */
	void				setGrade(int grade);
	void				incrementGrade();
	void				decrementGrade();

/* Methods */
	void	signForm(Form &form);

/* Exceptions */
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