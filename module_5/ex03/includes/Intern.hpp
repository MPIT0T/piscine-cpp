#ifndef INTERN_HPP
# define INTERN_HPP

# include <AForm.hpp>
#include <map>

class Intern
{
public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();

	AForm *makeForm(const std::string &level, const std::string &target);

private:
	std::map<std::string, AForm *> _forms;
};



#endif //INTERN_HPP
