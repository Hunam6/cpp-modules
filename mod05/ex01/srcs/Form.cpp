#include "Form.hpp"

Form::Form()
	: name(""),
	  gradeRequiredToSign(1),
	  gradeRequiredToExecute(1) {}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute)
	: name(name),
	  gradeRequiredToSign(gradeRequiredToSign),
	  gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (this->gradeRequiredToSign > 150 || this->gradeRequiredToExecute > 150)
		throw GradeTooLowException("invalid grade, must be 1 <= grade <= 150");
	if (this->gradeRequiredToSign < 1 || this->gradeRequiredToExecute < 1)
		throw GradeTooHighException("invalid grade, must be 1 <= grade <= 150");
}

Form::Form(Form &other)
	: name(other.name),
	  gradeRequiredToSign(other.gradeRequiredToSign),
	  gradeRequiredToExecute(other.gradeRequiredToExecute)
{
	if (this->gradeRequiredToSign > 150 || this->gradeRequiredToExecute > 150)
		throw GradeTooLowException("invalid grade, must be 1 <= grade <= 150");
	if (this->gradeRequiredToSign < 1 || this->gradeRequiredToExecute < 1)
		throw GradeTooHighException("invalid grade, must be 1 <= grade <= 150");
	isSigned = other.isSigned;
}

Form::~Form() {}

Form &Form::operator=(Form &other)
{
	isSigned = other.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Form &other)
{
	stream << other.getName() << ", form ";
	if (!other.getSignedStatus())
		stream << "not ";
	stream << "signed, requires grade " << other.getGradeRequiredToSign() << " to sign, "
		   << "requires grade " << other.getGradeRequiredToExecute() << " to execute.\n";
	return stream;
}

std::string Form::getName() const
{
	return name;
}

int Form::getSignedStatus() const
{
	return isSigned;
}

int Form::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeRequiredToSign)
		isSigned = true;
	else
		throw GradeTooLowException("grade to low to sign the form");
}
