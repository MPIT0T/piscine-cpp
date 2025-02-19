#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <AForm.hpp>

class RobotomyRequestForm : public AForm
{
public:
/* Constructors */
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

/* Operators */
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	
/* Methods */
	void execute(Bureaucrat const& executor) const;

private:
	std::string _target;
	RobotomyRequestForm();
};



#endif //ROBOTOMYREQUESTFORM_HPP
