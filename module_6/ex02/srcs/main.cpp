#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	std::srand(std::time(0));
	int randValue = std::rand() % 3;

	if (randValue == 0)
		return new A();
	if (randValue == 1)
		return new B();
	if (randValue == 2)
		return new C();
	return (NULL);
}

void identify(Base *ptr)
{
	if (ptr == NULL)
		std::cout << "NULL pointer" << std::endl;
	else if (dynamic_cast<A *>(ptr))
		std::cout << "type A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "type B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "type C" << std::endl;
	else
		std::cout << "tf are you doing man" << std::endl;
}

void identify(Base &ref)
{
	try
	{
		static_cast<void>(dynamic_cast<A &>(ref));
		std::cout << "type A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		static_cast<void>(dynamic_cast<B &>(ref));
		std::cout << "type B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		static_cast<void>(dynamic_cast<C &>(ref));
		std::cout << "type C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	std::cout << "tf are you doing man" << std::endl;
}


int	main(void)
{
	Base *test = generate();

	identify(NULL); //should output "NULL pointer"

	identify(test); //should output the A, B or C

	if (test != NULL) //good practice, but never happens to be NULL
		identify(*test); //should output the same type as the test before

	delete test;
	return (0);

}