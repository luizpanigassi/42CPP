#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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
	std::cout << BOLD << CYAN << "======== Intern tests starting ========" << RESET << std::endl;
	std::cout << std::endl;

	// ===== Test 1 =====
	std::cout << BOLD << YELLOW << "===== Test 1 =====" << RESET << std::endl;
	try
	{
		Intern someLoser;
		AForm* rrf = NULL;

		std::cout << MAGENTA << "=== Creating a bureaucrat ===" << RESET << std::endl;
		Bureaucrat suzana("Suzana Cagliostro", 1);
		std::cout << GREEN << suzana << RESET << std::endl;

		std::cout << MAGENTA << "=== Creating a form ===" << RESET << std::endl;
		rrf = someLoser.makeForm("presidential pardon", "Ford Prefect, the 'human'");
		std::cout << BLUE << *rrf << RESET << std::endl;

		std::cout << MAGENTA << "=== Signing & executing the form ===" << RESET << std::endl;
		suzana.signForm(*rrf);
		suzana.executeForm(*rrf);

		delete rrf;
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
		Intern someLoser;
		AForm* rrf2 = NULL;

		std::cout << MAGENTA << "=== Creating a bureaucrat ===" << RESET << std::endl;
		Bureaucrat william("William Shostner", 150);
		std::cout << GREEN << william << RESET << std::endl;

		std::cout << MAGENTA << "=== Creating a form ===" << RESET << std::endl;
		rrf2 = someLoser.makeForm("robotomy request", "Bender, the alcoholic");
		std::cout << BLUE << *rrf2 << RESET << std::endl;

		std::cout << MAGENTA << "=== Signing & executing the form ===" << RESET << std::endl;
		william.signForm(*rrf2);
		william.executeForm(*rrf2);

		delete rrf2;
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
		Intern someLoser;
		AForm* rrf3 = NULL;

		std::cout << MAGENTA << "=== Creating a bureaucrat ===" << RESET << std::endl;
		Bureaucrat frenchman("The Frenchman in the Castle", 100);
		std::cout << GREEN << frenchman << RESET << std::endl;

		std::cout << MAGENTA << "=== Creating a form ===" << RESET << std::endl;
		rrf3 = someLoser.makeForm("shrubbery creation", "Lancelot, the brave");
		std::cout << BLUE << *rrf3 << RESET << std::endl;

		std::cout << MAGENTA << "=== Signing & executing the form ===" << RESET << std::endl;
		frenchman.signForm(*rrf3);
		frenchman.executeForm(*rrf3);

		delete rrf3;
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
		Intern someLoser;
		AForm* rrf4 = NULL;

		std::cout << MAGENTA << "=== Creating a bureaucrat ===" << RESET << std::endl;
		Bureaucrat niceBoss("A nice boss", 1);
		std::cout << GREEN << niceBoss << RESET << std::endl;

		std::cout << MAGENTA << "=== Creating a form ===" << RESET << std::endl;
		rrf4 = someLoser.makeForm("give intern a raise", "The Intern");
		if (!rrf4) throw std::runtime_error("Form creation failed!");
		std::cout << BLUE << *rrf4 << RESET << std::endl;

		std::cout << MAGENTA << "=== Signing & executing the form ===" << RESET << std::endl;
		niceBoss.signForm(*rrf4);
		niceBoss.executeForm(*rrf4);

		delete rrf4;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	return 0;
}
