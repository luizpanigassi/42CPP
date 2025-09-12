#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
public:
	// Constructors and Destructor
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

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

	class ExecuteGradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
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
	void execute(Bureaucrat const & executor) const;
	virtual void executeAction() const = 0;

private:
	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;
	bool isSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
