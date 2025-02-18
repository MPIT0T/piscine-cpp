#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <Bureaucrat.hpp>
#include <fstream>


/* Constructors ************************************************************* */
ShrubberyCreationForm::ShrubberyCreationForm() : _target("undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Operators **************************************************************** */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	return (*this);
}

/* Methods ****************************************************************** */
void ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
	if (executor.getGrade() > gradeToExecute())
		throw (GradeTooLowException());

	std::string		fileName = _target + "_shrubbery";
	std::ofstream	file(fileName.data());
	if (!file)
		throw (std::runtime_error("error opening file."));

	file << "                  %%%,%%%%%%%" << std::endl;
	file << "                   ,'%% \\-*%%%%%%%" << std::endl;
	file << "             ;%%%%%*%   _%%%%\"" << std::endl;
	file << "              ,%%%       \\(_.*%%%%." << std::endl;
	file << "              % *%%, ,%%%%*(    '" << std::endl;
	file << "            %^     ,*%%% )\\|,%%*%,_" << std::endl;
	file << "                 *%    \\/ #).-\"*%%*" << std::endl;
	file << "                     _.) ,/ *%," << std::endl;
	file << "             _________/)#(_____________" << std::endl;

	file.close();

	std::cout << executor.getName() << " executed " << this->name();
}
