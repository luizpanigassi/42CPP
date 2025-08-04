#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "A wild Harl appears!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl has fainted!" << std::endl;
	std::cout << std::endl;
}

void Harl::debug()
{
	std::cout << "Debugging..." << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
	std::cout << "Debugging complete!" << std::endl;
}

void Harl::info()
{
	std::cout << "Information display:" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << "Information displayed!" << std::endl;
}

void Harl::warning()
{
	std::cout << "Warning!" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << "Warning issued!" << std::endl;
}

void Harl::error()
{
	std::cout << "Error triggered!" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << "Error handled!" << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlFunction)();
	HarlFunction functions[] =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4 && levels[i] != level)
		i++;

	if (i < 4)
		(this->*functions[i])();

	else
		std::cerr << "Harl is not aware of the level: " << level << std::endl;

	std::cout << std::endl;
	std::cout << "Harl has finished complaining, now he's happy. I think." << std::endl;
}
