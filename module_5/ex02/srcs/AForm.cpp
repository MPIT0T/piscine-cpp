#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("undefined"), _signState(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute) : _name(name), _signState(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::AForm(const AForm &src): _name(src.getName()), _signState(src.getSignState()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		_signState = src.getSignState();
	return *this;
}

const std::string &AForm::getName() const { return _name; }

const bool &AForm::getSignState() const { return _signState; }

const int &AForm::getGradeToSign() const { return _gradeToSign; }

const int &AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	if (_signState == true)
		throw FormAlreadySignedException();
	_signState = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "Form already signed";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form needs to be signed to be executed";
}

std::ostream &operator<<(std::ostream &OUT, const AForm &form)
{
	OUT << "Form " << form.getName() << ", requires grade " << form.getGradeToSign() << " to sign, " << form.getGradeToExecute() << " to execute. Signed: ";
	if (form.getSignState())
		OUT << "Yes.";
	else
		OUT << "No.";
	return OUT;
}