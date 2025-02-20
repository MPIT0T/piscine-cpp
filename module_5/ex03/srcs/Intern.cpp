#include "Intern.hpp"
#include <iostream>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

/* Constructors ************************************************************* */
Intern::Intern() {}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern() {}

/* Operators **************************************************************** */
Intern &Intern::operator=(const Intern &src)
{
	(void) src;
	return (*this);
}

/* Methods ****************************************************************** */
static unsigned int hash_level(const std::string &level)
{
	unsigned int hash = 0;

	for (unsigned int i = 0; level[i]; i++)
		hash = hash * 31 + level[i];

	return (hash);
}

AForm *Intern::makeForm(const std::string &level, const std::string &target)
{
	switch (hash_level(level))
	{
		case 512388267:
		{
			std::cout << "Intern creates " << level << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 2877915424:
		{
			std::cout << "Intern creates " << level << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 886341134:
		{
			std::cout << "Intern creates " << level << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
		{
			std::cout << "This form doesn't exist" << std::endl;
			return (NULL);
		}
	}
}
