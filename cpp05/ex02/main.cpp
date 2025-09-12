#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// ANSI colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "======== Form tests starting ========" << RESET << std::endl;
	std::cout << std::endl;

	// ===== Test 1 =====
	std::cout << BOLD << YELLOW << "===== Test 1 =====" << RESET << std::endl;
	try
	{
		Bureaucrat suzana("Suzana Cagliostro", 1);
		std::cout << GREEN << suzana << RESET << std::endl;

		AForm *form1 = new PresidentialPardonForm("Arthur Dent, the human");
		std::cout << BLUE << *form1 << RESET << std::endl;

		std::cout << MAGENTA << "=== Signing form ===" << RESET << std::endl;
		suzana.signForm(*form1);
		std::cout << BLUE << *form1 << RESET << std::endl;

		std::cout << MAGENTA << "=== Executing form ===" << RESET << std::endl;
		suzana.executeForm(*form1);

		delete form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// ===== Test 2 =====
	std::cout << BOLD << YELLOW << "===== Test 2 =====" << RESET << std::endl;
	try
	{
		Bureaucrat william("William Shostner", 150);
		std::cout << GREEN << william << RESET << std::endl;

		AForm *form2 = new RobotomyRequestForm("Marvin, the Paranoid Android");
		std::cout << BLUE << *form2 << RESET << std::endl;

		std::cout << MAGENTA << "=== Signing form ===" << RESET << std::endl;
		william.signForm(*form2);
		std::cout << BLUE << *form2 << RESET << std::endl;

		std::cout << MAGENTA << "=== Executing form ===" << RESET << std::endl;
		william.executeForm(*form2);

		delete form2;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// ===== Test 3 =====
	std::cout << BOLD << YELLOW << "===== Test 3 =====" << RESET << std::endl;
	try
	{
		Bureaucrat frenchman("The Frenchman in the Castle", 100);
		std::cout << GREEN << frenchman << RESET << std::endl;

		AForm *form3 = new ShrubberyCreationForm("King Arthur, the king");
		std::cout << BLUE << *form3 << RESET << std::endl;

		std::cout << MAGENTA << "=== Signing form ===" << RESET << std::endl;
		frenchman.signForm(*form3);
		std::cout << BLUE << *form3 << RESET << std::endl;

		std::cout << MAGENTA << "=== Executing form ===" << RESET << std::endl;
		frenchman.executeForm(*form3);

		delete form3;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// ===== Test 4 =====
	std::cout << BOLD << YELLOW << "===== Test 4 =====" << RESET << std::endl;
	try
	{
		Bureaucrat suzana("Suzana", 1);
		std::cout << GREEN << suzana << RESET << std::endl;

		AForm *form4 = new PresidentialPardonForm("Arthur Dent");
		std::cout << BLUE << *form4 << RESET << std::endl;

		std::cout << MAGENTA << "=== Attempting execution before signing ===" << RESET << std::endl;
		suzana.executeForm(*form4);

		std::cout << MAGENTA << "=== Signing form ===" << RESET << std::endl;
		suzana.signForm(*form4);
		std::cout << BLUE << *form4 << RESET << std::endl;

		std::cout << MAGENTA << "=== Executing form ===" << RESET << std::endl;
		suzana.executeForm(*form4);

		delete form4;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	return 0;
}
