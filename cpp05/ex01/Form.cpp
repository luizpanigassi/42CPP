#include "Form.hpp"

// Constructors/Destructors
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned){}

Form &Form::operator=(const Form &other)
{
	if(this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form(){}

// Getters
bool Form::getIsSigned() const
{
	return isSigned;
}

const std::string& Form::getName() const
{
	return name;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return "The form grade requirement is too high! Be nicer to the workers!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "The form grade requirement is too low! We're not stupid here!";
}

// Actions
void Form::beSigned(const Bureaucrat& b)
{
	if(b.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

// Overloaders
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", requires grade " << form.getGradeToSign() << " to be signed and grade "
		<< form.getGradeToExecute() << " to be executed. Signed status: "
		<< (form.getIsSigned() ? "Signed" : "Not Signed") << ".";
	return os;
}
