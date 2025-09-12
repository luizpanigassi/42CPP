#include <Bureaucrat.hpp>

// ANSI colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "======== Bureaucrat Tests ========" << RESET << std::endl << std::endl;

	// ===== Test 1 =====
	std::cout << BOLD << YELLOW << "===== Test 1: Demotion =====" << RESET << std::endl;
	try
	{
		Bureaucrat suzana("Suzana Cagliostro", 1);
		std::cout << GREEN << suzana << RESET << std::endl;

		std::cout << MAGENTA << "Demoting..." << RESET << std::endl;
		suzana.demote();
		std::cout << GREEN << suzana << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// ===== Test 2 =====
	std::cout << BOLD << YELLOW << "===== Test 2: Promotion =====" << RESET << std::endl;
	try
	{
		Bureaucrat william("William Shostner", 150);
		std::cout << GREEN << william << RESET << std::endl;

		std::cout << MAGENTA << "Promoting..." << RESET << std::endl;
		william.promote();
		std::cout << GREEN << william << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// ===== Test 3 =====
	std::cout << BOLD << YELLOW << "===== Test 3: Invalid High Grade =====" << RESET << std::endl;
	try
	{
		Bureaucrat jorel("Jorel", 0);
		std::cout << GREEN << jorel << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// ===== Test 4 =====
	std::cout << BOLD << YELLOW << "===== Test 4: Invalid Low Grade =====" << RESET << std::endl;
	try
	{
		Bureaucrat irmao_do_jorel("Irmão do Jorel", 151);
		std::cout << GREEN << irmao_do_jorel << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	return 0;
}
