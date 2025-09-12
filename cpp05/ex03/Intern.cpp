#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Helper functions

AForm* createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

// typedef & Struct

typedef AForm* (*FormCreator)(const std::string& target);

struct FormPair
{
	const char* name;
	FormCreator creator;
};

// Constructors/Destructor
Intern::Intern(){}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern(){}

// Action

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	FormPair formPairs[] = {
		{"shrubbery creation", &createShrubberyForm},
		{"robotomy request", &createRobotomyForm},
		{"presidential pardon", &createPresidentialForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formPairs[i].name)
		{
			std::cout << "Intern created " << formName << " form. Good job, tiny monkey!" << std::endl;
			return formPairs[i].creator(target);
		}
	}
	throw std::runtime_error("Error: your form '" + formName + "' does not exist. It's the intern's fault, of course."
);
	return 0;
}

