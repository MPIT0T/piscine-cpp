/* ***************** */
/*      WebServ      */
/* ***************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* Constructors ************************************************************* */
AForm::AForm() : _name("undefined"), _signState(false), _gradeToSign(-1), _gradeToExecute(-1) {}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _signState(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::AForm(const AForm &src) : _name(src._name), _signState(false), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm::~AForm() {}

/* Operators **************************************************************** */
AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		_signState = src.signState();
	return (*this);
}

/* Getters ****************************************************************** */
const std::string &AForm::name() const { return (_name); }

const bool &AForm::signState() const { return (_signState); }

const int &AForm::gradeToSign() const { return (_gradeToSign); }

const int &AForm::gradeToExecute() const { return (_gradeToExecute); }

/* Setters ****************************************************************** */
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signState = true;
}

/* Exceptions *************************************************************** */
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form needs to be signed to be executed");
}

/* ostream ****************************************************************** */
std::ostream& operator<<(std::ostream &OUT, AForm &form)
{
	OUT << "FORM :" << std::endl
		<< "name : " << form.name() << std::endl
		<< "signed : " << form.signState() << std::endl
		<< "grade to sign : " << form.gradeToSign() << std::endl
		<< "grade to execute : " << form.gradeToExecute() << std::endl
		<< std::endl;

	return (OUT);
}
