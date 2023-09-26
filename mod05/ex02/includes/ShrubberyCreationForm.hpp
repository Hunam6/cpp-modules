#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);

	void execute(const Bureaucrat &executor) const;
};

#endif
