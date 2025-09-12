#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

class Intern {
public:
	// Constructors and Destructor
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
};

#endif
