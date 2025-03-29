#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &bureaucrat) const;

private:
	std::string	_target;

	PresidentialPardonForm();
};

#endif
