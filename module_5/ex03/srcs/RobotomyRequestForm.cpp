#include "RobotomyRequestForm.hpp"
#include <Bureaucrat.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
AForm(),
_target("undefined")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
AForm(src)
{
	_target = src._target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!getSignState())
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::srand(std::time(0));
	int		randomNumber = std::rand() % 2;
	if (randomNumber == 0)
		std::cout << bureaucrat.getName() << " has been robotomised." << std::endl;
	else
		std::cout << bureaucrat.getName() << "'s robotomy failed." << std::endl;
}

AForm *RobotomyRequestForm::clone(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}