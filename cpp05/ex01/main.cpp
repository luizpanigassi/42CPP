#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << BOLD << CYAN << "======== Bureaucrat tests started ========" << RESET << std::endl << std::endl;

	// ===== Bureaucrat promotions/demotions =====
	std::cout << BOLD << YELLOW << "===== Bureaucrat Tests =====" << RESET << std::endl;
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

	// ===== Form signing tests =====
	std::cout << BOLD << CYAN << "======== Form tests ========" << RESET << std::endl << std::endl;

	// Test 1
	std::cout << BOLD << YELLOW << "===== Test 1 =====" << RESET << std::endl;
	try
	{
		Form movieForm("Form to approve Steve Magal movie", 1, 1);
		Bureaucrat suzana("Suzana Cagliostro", 1);
		std::cout << GREEN << suzana << RESET << std::endl;

		std::cout << MAGENTA << "Signing form..." << RESET << std::endl;
		suzana.signForm(movieForm);
		std::cout << BLUE << movieForm << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// Test 2
	std::cout << BOLD << YELLOW << "===== Test 2 =====" << RESET << std::endl;
	try
	{
		Form concertForm("Form to approve Underpants on Fire concert", 1, 1);
		Bureaucrat william("William Shostner", 150);
		std::cout << GREEN << william << RESET << std::endl;

		std::cout << MAGENTA << "Signing form..." << RESET << std::endl;
		william.signForm(concertForm);
		std::cout << BLUE << concertForm << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// Test 3
	std::cout << BOLD << YELLOW << "===== Test 3 =====" << RESET << std::endl;
	try
	{
		Form fireJorelForm("Form to fire Jorel", 0, 0);
		Bureaucrat suzana("Suzana Cagliostro", 1);
		std::cout << GREEN << suzana << RESET << std::endl;

		std::cout << MAGENTA << "Signing form..." << RESET << std::endl;
		suzana.signForm(fireJorelForm);
		std::cout << BLUE << fireJorelForm << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// Test 4
	std::cout << BOLD << YELLOW << "===== Test 4 =====" << RESET << std::endl;
	try
	{
		Form promoteIrmaoForm("Form to promote Irmão do Jorel", 151, 151);
		Bureaucrat jorel("Jorel", 1);
		std::cout << GREEN << jorel << RESET << std::endl;

		std::cout << MAGENTA << "Signing form..." << RESET << std::endl;
		jorel.signForm(promoteIrmaoForm);
		std::cout << BLUE << promoteIrmaoForm << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	// Test 5
	std::cout << BOLD << YELLOW << "===== Test 5 =====" << RESET << std::endl;
	try
	{
		Form abacateForm("Form buy all avocados", 1, 1);
		Bureaucrat vovoJuju("Vovó Juju", 2);
		std::cout << GREEN << vovoJuju << RESET << std::endl;

		std::cout << MAGENTA << "Signing form..." << RESET << std::endl;
		vovoJuju.signForm(abacateForm);
		std::cout << BLUE << abacateForm << RESET << std::endl;

		std::cout << MAGENTA << "Promoting and signing again..." << RESET << std::endl;
		vovoJuju.promote();
		vovoJuju.signForm(abacateForm);
		std::cout << BLUE << abacateForm << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	std::cout << BOLD << CYAN << "======== Form tests ended ========" << RESET << std::endl << std::endl;

	return 0;
}
