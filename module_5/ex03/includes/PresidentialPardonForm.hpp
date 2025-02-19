#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include <AForm.hpp>


class PresidentialPardonForm : public AForm
{
public:
/* Constructors */
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

/* Operators */
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	
/* Methods */
	void execute(Bureaucrat const& executor) const;

private:
	std::string	_target;
	PresidentialPardonForm();
};



#endif //PRESIDENTIALPARDONFORM_HPP
