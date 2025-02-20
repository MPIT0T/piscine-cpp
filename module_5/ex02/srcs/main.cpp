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

	ShrubberyCreationForm	scf("test");
	RobotomyRequestForm		rrf("Tom");
	PresidentialPardonForm	ppf("Sebastien");

	try
	{
		// scf.execute(fred);			//should throw "Form needs to be signed to be executed"
		// scf.beSigned(fred);			//should throw "Grade too low"

		scf.beSigned(michel);
		scf.execute(michel);

		michel.setGrade(72);
		rrf.beSigned(michel);
		rrf.execute(seb);

		ppf.beSigned(seb);
		ppf.execute(zaphod);

		std::cout << "All operations done successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}