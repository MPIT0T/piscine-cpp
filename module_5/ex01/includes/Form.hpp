/* ***************** */
/*      WebServ      */
/* ***************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form
{
public:
/* Constructors */
	Form(const std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &src);
	~Form();

/* Operators */
	Form &operator=(const Form &src);

/* Getters */
	const std::string	&name();
	bool				&signState();
	const int			&gradeToSign();
	const int			&gradeToExecute();

/* Setters */
	void				beSigned(const Bureaucrat &bureaucrat);

/* Exceptions */
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

std::ostream&	operator<<(std::ostream OUT, Form &form);

#endif //FORM_HPP
