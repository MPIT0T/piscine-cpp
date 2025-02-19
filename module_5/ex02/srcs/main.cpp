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
		fred.incrementGrade();
		fred.decrementGrade();
		// fred.decrementGrade();	//should throw "grade too low"

		michel.decrementGrade();
		michel.incrementGrade();
		michel.setGrade(3);

		// seb.incrementGrade();	//should throw "grade too high"

		// scf.execute(fred);			//should throw "Form needs to be signed to be executed"
		// scf.beSigned(fred);			//should throw "Grade too low"

		scf.beSigned(michel);
		scf.execute(michel);

		std::cout << "All operations done successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}