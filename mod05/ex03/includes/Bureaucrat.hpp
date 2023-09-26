#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat &other);

	std::string getName() const;
	int getGrade() const;
	void promote();
	void demote();
	void signForm(AForm &form) const;
	void executeForm(const AForm &form) const;

	class GradeTooHighException : public std::runtime_error
	{
	public:
		GradeTooHighException() : std::runtime_error("Grade must be 1 or lower") {}
	};

	class GradeTooLowException : public std::runtime_error
	{
	public:
		GradeTooLowException() : std::runtime_error("Grade must be 150 or higher") {}
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);

#endif
