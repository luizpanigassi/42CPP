#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors/Destructors
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned){}

AForm &AForm::operator=(const AForm &other)
{
	if(this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm(){}

// Getters
bool AForm::getIsSigned() const
{
	return isSigned;
}

const std::string& AForm::getName() const
{
	return name;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "The form grade requirement is too high! Be nicer to the workers!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "The form grade requirement is too low! We're not stupid here!";
}

const char* AForm::ExecuteGradeTooLowException::what() const throw()
{
	return "The form grade requirement is too low to execute! We're not stupid here!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "The form hasn't been signed!";
}

// Actions
void AForm::beSigned(const Bureaucrat& b)
{
	if(b.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if(!isSigned)
		throw FormNotSignedException();
	if(executor.getGrade() > gradeToExecute)
		throw ExecuteGradeTooLowException();
	executeAction();
}

// Overloaders
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form " << form.getName() << ", requires grade " << form.getGradeToSign() << " to be signed and grade "
		<< form.getGradeToExecute() << " to be executed. Signed status: "
		<< (form.getIsSigned() ? "Signed" : "Not Signed") << ".";
	return os;
}
