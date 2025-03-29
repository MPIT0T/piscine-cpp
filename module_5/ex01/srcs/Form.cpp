#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() :
_name("undefined"),
_signState(false), _gradeToSign(1),
_gradeToExecute(150)
{}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute) : _name(name), _signState(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute > 150)
		throw GradeTooHighException();
}

Form::Form(const Form &src): _name(src.getName()), _signState(src.getSignState()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		_signState = src.getSignState();
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return (_name); }

const bool &Form::getSignState() const { return (_signState); }

const int &Form::getGradeToSign() const { return (_gradeToSign); }

const int &Form::getGradeToExecute() const { return (_gradeToExecute); }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	if (_signState == true)
		throw FormAlreadySignedException();
	_signState = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed!");
}

std::ostream &operator<<(std::ostream &OUT, const Form &form)
{
	OUT << "Form " << form.getName() << ", requires grade " << form.getGradeToSign() << " to sign, " << form.getGradeToExecute() << " to execute. Signed: ";
	if (form.getSignState())
		OUT << "Yes.";
	else
		OUT << "No.";
	return (OUT);
}
