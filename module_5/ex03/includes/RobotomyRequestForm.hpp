#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <AForm.hpp>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &bureaucrat) const;
	AForm *clone(const std::string &target) const;

private:
	std::string _target;

	RobotomyRequestForm();
};

#endif
