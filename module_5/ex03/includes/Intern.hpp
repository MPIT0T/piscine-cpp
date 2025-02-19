#ifndef INTERN_HPP
# define INTERN_HPP
#include <AForm.hpp>

class Intern
{
public:
/* Constructors */
	Intern();
	Intern(const Intern &src);
	~Intern();

/* Operators */
	Intern &operator=(const Intern &src);
	
/* Methods */
	AForm *makeForm(const std::string &level, const std::string &target);
private:
	
};



#endif //INTERN_HPP
