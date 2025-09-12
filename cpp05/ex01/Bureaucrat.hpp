#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

// Forward declaration
class Form;

class Bureaucrat
{
	private:
		std::string const name;
		int grade;

	public:
		// Constructor/Destructor
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat (const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		// Getters
		int getGrade() const;
		const std::string& getName() const;

		// Actions
		void promote();
		void demote();
		void signForm(Form &form);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
