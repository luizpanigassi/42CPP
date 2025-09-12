#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	// Constructors and Destructor
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm & other);
	PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
	~PresidentialPardonForm();

	// Actions
	void executeAction() const;

private:
	std::string target;
};

#endif
