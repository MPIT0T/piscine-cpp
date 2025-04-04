#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <string>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, const int &grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	const std::string	&getName() const;
	const int			&getGrade() const;

	void	setGrade(const int &grade);

	void	incrementGrade();
	void	decrementGrade();

	void signForm(AForm &form) const;
	void executeForm(const AForm &form) const;

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

private:
	const std::string	_name;
	int					_grade;


};

std::ostream &operator<<(std::ostream &OUT, const Bureaucrat &bureaucrat);

#endif