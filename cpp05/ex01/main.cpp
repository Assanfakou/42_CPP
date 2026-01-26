#include <iostream>
#include "Bureaucrat.h"

int main () 
{
	std::cout << "--------------- no exception catched ----------------\n";
	try 
	{
		Bureaucrat assan("assan", 2);
		assan.incrementGrade();
		std::cout << assan << std::endl;
		assan.decrementGrade();
		std::cout << assan << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------- grade high exception ----------------\n";
	try 
	{
		Bureaucrat assan("bron", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "--------------- grade Low exception ----------------\n";
	try 
	{
		Bureaucrat assan("freak", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
