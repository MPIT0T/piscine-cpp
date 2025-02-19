#include "RobotomyRequestForm.hpp"
#include <Bureaucrat.hpp>
#include <cstdlib>
#include <ctime>

/* Constructors ************************************************************* */
RobotomyRequestForm::RobotomyRequestForm() :
AForm(),
_target("undefined")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 5),
_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
AForm(src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* Operators **************************************************************** */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		this->AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

/* Methods ****************************************************************** */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > gradeToSign())
		throw (AForm::GradeTooLowException());

	std::srand(std::time(0));
	int		randomNumber = std::rand() % 2;
	if (randomNumber == 0)
		std::cout << executor.getName() << " has been robotomised." << std::endl;
	else
		std::cout << executor.getName() << "'s robotomy failed." << std::endl;
}
