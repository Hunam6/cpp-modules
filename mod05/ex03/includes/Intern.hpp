#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm *createShrubberyCreationForm(std::string target) const;
	AForm *createRobotomyRequestForm(std::string target) const;
	AForm *createPresidentialPardonForm(std::string target) const;

public:
	Intern();
	Intern(Intern &other);
	~Intern();

	Intern &operator=(Intern &other);

	AForm *makeForm(std::string formName, std::string formTarget) const;
};

#endif
