#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);

	void execute(const Bureaucrat &executor) const;
};

#endif
