#include "Intern.hpp"
#include <iostream>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
	(void) src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src)
{
	(void) src;
	return *this;
}

const char *Intern::UnknownFormException::what() const throw()
{
	return "Unknown form";
}

AForm * Intern::makeShrubberyCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm * Intern::makeRobotomyRequestForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::makePresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	const std::string names[] =
		{
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
	AForm *(Intern::*makers[])(const std::string &) const =
		{
			&Intern::makeShrubberyCreationForm,
			&Intern::makeRobotomyRequestForm,
			&Intern::makePresidentialPardonForm
		};
	for (size_t i = 0; i < 3; ++i)
	{
		if (names[i] == formName)
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			return (this->*makers[i])(target);
		}
	}

	return NULL;
}
