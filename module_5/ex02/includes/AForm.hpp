#ifndef FORM_HPP
# define FORM_HPP

# include <string>
class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string &name, const int &gradeToSign, const int &gradeToExecute);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	const std::string	&getName() const;
	const bool			&getSignState() const;
	const int			&getGradeToSign() const;
	const int			&getGradeToExecute() const;

	void				beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(const Bureaucrat &bureaucrat) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
	public :
		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public :
		const char *what() const throw();
	};

private:
	const std::string	_name;
	bool				_signState;
	const int			_gradeToSign;
	const int			_gradeToExecute;

};

std::ostream&	operator<<(std::ostream &OUT, const AForm &form);

#endif //FORM_HPP
