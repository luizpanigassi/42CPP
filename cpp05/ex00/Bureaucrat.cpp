#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	std::cout << "Creating Bureaucrat " << name << "! On with business!" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if(this != &other)
		grade = other.grade;
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Get off your high horse!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Git gud, noob!";
}

void Bureaucrat::promote()
{
	if (grade > 1)
		--grade;

}

void Bureaucrat::demote()
{
	if (grade < 150)
		++grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
