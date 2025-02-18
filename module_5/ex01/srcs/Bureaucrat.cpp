/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:01:25 by mpitot            #+#    #+#             */
/*   Updated: 2024/10/15 15:16:46 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Constructors ************************************************************* */
Bureaucrat::Bureaucrat() : _name("undefined"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

/* Operators **************************************************************** */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return *this;
}

/* Getters ****************************************************************** */
const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

const int& Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/* Setters ****************************************************************** */
void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

/* Methods ****************************************************************** */
void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(this);
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.name() << " because \"" << e.what() << "\"" << std::endl;
	}
}

/* Exceptions *************************************************************** */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/* ostream ****************************************************************** */
std::ostream& operator<<(std::ostream &OUT, const Bureaucrat& bureaucrat)
{
	OUT << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (OUT);
}
