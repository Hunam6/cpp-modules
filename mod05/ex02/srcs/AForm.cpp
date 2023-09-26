#include "AForm.hpp"

AForm::AForm()
	: name(""),
	  gradeRequiredToSign(1),
	  gradeRequiredToExecute(1) {}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute)
	: name(name),
	  gradeRequiredToSign(gradeRequiredToSign),
	  gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (this->gradeRequiredToSign > 150 || this->gradeRequiredToExecute > 150)
		throw GradeTooLowException("invalid grade, must be 1 <= grade <= 150");
	if (this->gradeRequiredToSign < 1 || this->gradeRequiredToExecute < 1)
		throw GradeTooHighException("invalid grade, must be 1 <= grade <= 150");
}

AForm::AForm(AForm &other)
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

AForm::~AForm() {}

AForm &AForm::operator=(AForm &other)
{
	isSigned = other.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const AForm &other)
{
	stream << other.getName() << ", form ";
	if (!other.getSignedStatus())
		stream << "not ";
	stream << "signed, requires grade " << other.getGradeRequiredToSign() << " to sign, "
		   << "requires grade " << other.getGradeRequiredToExecute() << " to execute.\n";
	return stream;
}

std::string AForm::getName() const
{
	return name;
}

int AForm::getSignedStatus() const
{
	return isSigned;
}

int AForm::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeRequiredToSign)
		isSigned = true;
	else
		throw GradeTooLowException("the grade is too low to sign the form");
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned)
		throw FormNotSigned();
	if (executor.getGrade() >= gradeRequiredToExecute)
		throw GradeTooLowException("Grade too low to execute");
}
