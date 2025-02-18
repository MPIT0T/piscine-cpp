#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	fred("Frederique", 150);
	Bureaucrat	michel("Michel", 100);
	Bureaucrat	seb("Sebastien", 1);

	try
	{
		fred.incrementGrade();
		fred.decrementGrade();
		// fred.decrementGrade();	//should throw "grade too low"

		michel.decrementGrade();
		michel.incrementGrade();
		michel.setGrade(3);

		// seb.incrementGrade();	//should throw "grade too high"

		std::cout << "All operations done successfully";
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}