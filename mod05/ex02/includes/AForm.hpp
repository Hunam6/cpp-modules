#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

public:
	AForm();
	AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
	AForm(AForm &other);
	~AForm();

	AForm &operator=(AForm &other);

	std::string getName() const;
	int getSignedStatus() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::runtime_error
	{
	public:
		GradeTooHighException(std::string msg) : std::runtime_error(msg) {}
	};

	class GradeTooLowException : public std::runtime_error
	{
	public:
		GradeTooLowException(std::string msg) : std::runtime_error(msg) {}
	};

	class FormNotSigned : public std::runtime_error
	{
	public:
		FormNotSigned() : std::runtime_error("Form is not signed") {}
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &other);

#endif
