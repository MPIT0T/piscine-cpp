#include "PresidentialPardonForm.hpp"

#include <Bureaucrat.hpp>


/* Constructors ************************************************************* */
PresidentialPardonForm::PresidentialPardonForm() :
AForm(),
_target("undefined")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("PresidentialPardonForm", 25, 5),
_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
AForm(src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* Operators **************************************************************** */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		this->AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

/* Methods ****************************************************************** */
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > gradeToExecute())
		throw (GradeTooLowException());

	std::cout << executor.getName() << " has been pardonned by Zaphod Beeblebox." << std::endl;
}
