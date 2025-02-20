/* ***************** */
/*      WebServ      */
/* ***************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* Constructors ************************************************************* */
Form::Form() :
_name("undefined"),
_signState(false), _gradeToSign(-1),
_gradeToExecute(-1)
{}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) :
_name(name),
_signState(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{}

Form::Form(const Form &src) :
_name(src._name),
_signState(src._signState),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute)
{}

Form::~Form() {}

/* Operators **************************************************************** */
Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		_signState = src._signState;
	}
	return (*this);
}

/* Getters ****************************************************************** */
const std::string &Form::name()
{
	return (_name);
}

bool &Form::signState()
{
	return (_signState);
}

const int &Form::gradeToSign()
{
	return (_gradeToSign);
}

const int &Form::gradeToExecute()
{
	return (_gradeToExecute);
}

/* Setters ****************************************************************** */
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signState = true;
}

/* Exceptions *************************************************************** */
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

/* ostream ****************************************************************** */
std::ostream& operator<<(std::ostream &OUT, Form &form)
{
	OUT	<< "FORM :" << std::endl
		<< "name : " << form.name() << std::endl
		<< "signed : " << form.signState() << std::endl
		<< "grade to sign : " << form.gradeToSign() << std::endl
		<< "grade to execute : " << form.gradeToExecute() << std::endl
		<< std::endl;
	return (OUT);
}
