#include "Intern.hpp"
#include <iostream>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

Intern::Intern()
{
	_forms.insert(std::make_pair("shrubbery creation", new ShrubberyCreationForm("undefined")));
	_forms.insert(std::make_pair("robotomy request", new RobotomyRequestForm("undefined")));
	_forms.insert(std::make_pair("presidential pardon", new PresidentialPardonForm("undefined")));
}

Intern::Intern(const Intern &src)
{
	(void) src;
}

Intern::~Intern()
{
	for (std::map<std::string, AForm *>::iterator it = _forms.begin(); it != _forms.end(); ++it)
		delete it->second;
}

Intern &Intern::operator=(const Intern &src)
{
	(void) src;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *form = NULL;
	std::map<std::string, AForm *>::iterator it = _forms.find(formName);

	if (it != _forms.end())
	{
		form = it->second->clone(target);
		std::cout << "Intern creates " << formName << std::endl;
	}
	else
		std::cerr << "Intern cannot create " << formName << std::endl;
	return form;
}
