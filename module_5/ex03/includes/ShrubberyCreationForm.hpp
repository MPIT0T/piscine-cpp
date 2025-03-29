#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat &bureaucrat) const;
	AForm *clone(const std::string &target) const;

private:
	std::string _target;

	ShrubberyCreationForm();
};

#endif
