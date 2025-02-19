#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

#include "Bureaucrat.hpp"

static size_t hash_level(const std::string &level)
{
	size_t hash = 0;

	for (size_t i = 0; level[i]; i++)
		hash = hash * 31 + level[i];

	return (hash);
}

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

		std::cout << hash_level("shrubbery creation") << std::endl;
		std::cout << hash_level("robotomy request") << std::endl;
		std::cout << hash_level("presidential pardon") << std::endl;
		std::cout << "All operations done successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}