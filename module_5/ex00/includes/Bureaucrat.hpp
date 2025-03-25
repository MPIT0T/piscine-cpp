#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	const std::string	&getName() const;
	const int			&getGrade() const;

	void				setGrade(int grade);

	void				incrementGrade();
	void				decrementGrade();

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

private:
	const std::string	_name;
	int					_grade;

	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	Bureaucrat();

};

std::ostream &operator<<(std::ostream &OUT, const Bureaucrat &bureaucrat);

#endif