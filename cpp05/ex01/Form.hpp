#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	// Constructors and Destructor
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

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

	// Getters
	bool getIsSigned() const;
	const std::string& getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Actions
	void beSigned(const Bureaucrat& b);

private:
	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;
	bool isSigned;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
