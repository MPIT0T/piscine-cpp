#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class AForm
{
public:
/* Constructors */
	AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &src);
	virtual ~AForm();

/* Operators */
	AForm &operator=(const AForm &src);

/* Getters */
	const std::string	&name();
	bool				&signState();
	const int			&gradeToSign();
	const int			&gradeToExecute();

/* Setters */
	void				beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(Bureaucrat const & executor) const = 0;

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
};

std::ostream&	operator<<(std::ostream &OUT, AForm &form);

#endif //FORM_HPP
