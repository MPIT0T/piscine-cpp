#ifndef INTERN_HPP
# define INTERN_HPP

# include <AForm.hpp>
#include <map>

class Intern
{
public:
	Intern();
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target);

private:
	std::map<std::string, AForm *> _forms;

	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
};



#endif //INTERN_HPP
