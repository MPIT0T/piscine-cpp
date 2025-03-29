#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Creating Bureaucrats
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 50);
        Bureaucrat charlie("Charlie", 140);

        // Creating Forms
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bob");
        PresidentialPardonForm pardon("Alice");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Signing Forms
        std::cout << std::endl << "Charlie attempts to sign ShrubberyCreationForm:" << std::endl;
        charlie.signForm(shrubbery); // Should succeed

        std::cout << std::endl << "Bob attempts to sign RobotomyRequestForm:" << std::endl;
        bob.signForm(robotomy); // Should fail (grade too low)

        std::cout << std::endl << "Alice attempts to sign all forms:" << std::endl;
        alice.signForm(shrubbery);
        alice.signForm(robotomy);
        alice.signForm(pardon); // Should succeed

        // Executing Forms
        std::cout << std::endl << "Charlie attempts to execute ShrubberyCreationForm:" << std::endl;
        charlie.executeForm(shrubbery); // Should succeed (file creation)

        std::cout << std::endl << "Bob attempts to execute RobotomyRequestForm:" << std::endl;
        bob.executeForm(robotomy); // Should fail (grade too low)

        std::cout << std::endl << "Alice executes all forms:" << std::endl;
        alice.executeForm(shrubbery);
        alice.executeForm(robotomy);
        alice.executeForm(pardon); // Should succeed

        // Invalid Form Execution (Without Signing)
        PresidentialPardonForm unsignedForm("Dave");
        try
        {
            std::cout << std::endl << "Bob tries to execute an unsigned form:" << std::endl;
            bob.executeForm(unsignedForm); // Should fail (not signed)
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    return 0;
}
