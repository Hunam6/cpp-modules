#include "Intern.hpp"
#include <iostream>
#include <string>

Intern::Intern() {}

Intern::Intern(Intern &other)
{
	(void)other;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::createShrubberyCreationForm(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) const
{
	AForm *(Intern::*forms[])(std::string) const =
		{&Intern::createShrubberyCreationForm,
		 &Intern::createRobotomyRequestForm,
		 &Intern::createPresidentialPardonForm};
	const std::string formsName[] =
		{"shrubbery creation",
		 "robotomy request",
		 "presidential pardon"};

	for (int i = 0; i < 3; i++)
		if (formsName[i] == formName)
			return (this->*forms[i])(formTarget);

	std::cerr << "Form name is invalid.\n";
	return NULL;

	// for reference, the alternative that the subject depicts as "unreadable and ugly":
	/*
		if (formName == "shrubbery creation")
			return new ShrubberyCreationForm(formTarget);
		if (formName == "robotomy requestn")
			return new RobotomyRequestForm(formTarget);
		if (formName == "presidential pardon")
			return new PresidentialPardonForm(formTarget);
		return NULL;
	*/
}
