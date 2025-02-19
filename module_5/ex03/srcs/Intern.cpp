#include "Intern.hpp"
#include <iostream>
#include <map>
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
static size_t hash_level(const std::string &level)
{
	size_t hash = 0;

	for (size_t i = 0; level[i]; i++)
		hash = hash * 31 + level[i];

	return (hash);
}

AForm *Intern::makeForm(const std::string &level, const std::string &target)
{
	switch (hash_level(level))
	{
		case 14756678533376535723:
		{
			std::cout << "Intern creates " << level << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 11107267574772629792:
		{
			std::cout << "Intern creates " << level << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 7769190716560145934:
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
