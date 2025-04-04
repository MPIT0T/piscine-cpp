#ifndef INTERN_HPP
# define INTERN_HPP

# include <AForm.hpp>

class Intern
{
public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target) const;

	class UnknownFormException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	AForm *makeShrubberyCreationForm(const std::string &target) const;
	AForm *makeRobotomyRequestForm(const std::string &target) const;
	AForm *makePresidentialPardonForm(const std::string &target) const;
};



#endif //INTERN_HPP
