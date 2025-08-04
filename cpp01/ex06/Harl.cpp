#include "Harl.hpp"

Harl::Harl()
{
	std::cout << std::endl;
	std::cout << "A wild Harl appears!" << std::endl;
}

Harl::~Harl()
{
	std::cout << std::endl;
	std::cout << "Harl has fainted!" << std::endl;
	std::cout << std::endl;
}

void Harl::debug()
{
	std::cout << std::endl;
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
	std::cout << "[DEBUG OVER]" << std::endl;
}

void Harl::info()
{
	std::cout << std::endl;
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << "[INFO OVER]" << std::endl;
}

void Harl::warning()
{
	std::cout << std::endl;
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << "[WARNING OVER]" << std::endl;
}

void Harl::error()
{
	std::cout << std::endl;
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << "[ERROR OVER]" << std::endl;
}
