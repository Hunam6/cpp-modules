#pragma once
#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

public:
	Form();
	Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
	Form(Form &other);
	~Form();

	Form &operator=(Form &other);

	std::string getName() const;
	int getSignedStatus() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &os, const Form &other);

#endif
