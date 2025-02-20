#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	fred("Frederique", 150);
	Bureaucrat	michel("Michel", 100);
	Bureaucrat	seb("Sebastien", 25);
	Bureaucrat	zaphod("Zaphod Beeblebox", 1);

	Intern	someRandomIntern;
	AForm	*form;

	try
	{
		form = someRandomIntern.makeForm("shrubbery creation", "test");
		form->beSigned(michel);
		form->execute(michel);
		delete form ;

		form = someRandomIntern.makeForm("robotomy request", "Sebastien");
		form->beSigned(seb);
		form->execute(seb);
		delete form ;

		form = someRandomIntern.makeForm("presidential pardon", "Frederique");
		form->beSigned(zaphod);
		form->execute(zaphod);
		delete form ;

		std::cout << "All operations done successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}