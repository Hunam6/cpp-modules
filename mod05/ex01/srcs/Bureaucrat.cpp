#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: name(""), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
	: name(other.name)
{
	if (other.grade > 150)
		throw GradeTooLowException();
	if (other.grade < 1)
		throw GradeTooHighException();
	grade = other.grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	if (other.grade > 150)
		throw GradeTooLowException();
	if (other.grade < 1)
		throw GradeTooHighException();
	grade = other.grade;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &other)
{
	return stream << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::promote()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::demote()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName()
				  << " because " << e.what() << '\n';
	}
}
