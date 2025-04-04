#include "ShrubberyCreationForm.hpp"
#include <Bureaucrat.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!getSignState())
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::string		fileName = _target + "_shrubbery";
	std::ofstream	file(fileName.data());
	if (!file)
		throw std::runtime_error("error opening file.");

	file << "     ccee88oo" << std::endl;
	file << "  C8O8O8Q8PoOb o8oo" << std::endl;
	file << " dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "      \\\\\\//  /douUP" << std::endl;
	file << "        \\\\\\////" << std::endl;
	file << "         |||/\\" << std::endl;
	file << "         |||\\/" << std::endl;
	file << "         |||||" << std::endl;
	file << "   .....//||||\\...." << std::endl;

	file.close();
}
