#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);

	void execute(const Bureaucrat &executor) const;
};

#endif
