#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form
{
public:
	Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();

	const std::string	&getName() const;
	const bool			&getSignState() const;
	const int			&getGradeToSign() const;
	const int			&getGradeToExecute() const;;

	void	beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
	public :
		virtual const char *what() const throw();
	};

private:
	const std::string	_name;
	bool				_signState;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	Form();

};

std::ostream &operator<<(std::ostream &OUT, const Form &form);

#endif //FORM_HPP
