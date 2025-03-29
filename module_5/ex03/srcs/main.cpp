#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 50);

		// Intern creates forms
		AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Home");
		AForm* robotomyForm = intern.makeForm("robotomy request", "Bender");
		AForm* pardonForm = intern.makeForm("presidential pardon", "Zaphod");
		AForm* invalidForm = intern.makeForm("invalid form", "Nowhere");

		if (shrubberyForm)
		{
			alice.signForm(*shrubberyForm);
			alice.executeForm(*shrubberyForm);
			delete shrubberyForm;
		}

		if (robotomyForm)
		{
			bob.signForm(*robotomyForm); // Should fail
			alice.signForm(*robotomyForm); // Should succeed
			alice.executeForm(*robotomyForm);
			delete robotomyForm;
		}

		if (pardonForm)
		{
			alice.signForm(*pardonForm);
			alice.executeForm(*pardonForm);
			delete pardonForm;
		}

		if (invalidForm)
		{
			delete invalidForm; // Should never happen
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}
