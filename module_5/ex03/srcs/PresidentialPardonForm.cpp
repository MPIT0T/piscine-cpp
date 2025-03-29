#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
AForm(),
_target("undefined")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("PresidentialPardonForm", 25, 5),
_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	_target = src._target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!getSignState())
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << bureaucrat.getName() << " has been pardonned by Zaphod Beeblebox." << std::endl;
}

AForm *PresidentialPardonForm::clone(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}