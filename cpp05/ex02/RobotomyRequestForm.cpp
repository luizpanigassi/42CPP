#include "RobotomyRequestForm.hpp"

// Constructors/Destructor

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Actions

void RobotomyRequestForm::executeAction() const
{
	std::cout << "*Bzzzz Bzzz* Drilling noises..." << std::endl;
	if (rand() % 2)
		std::cout << target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "! Guess we'll just scrap him..." << std::endl;
}
