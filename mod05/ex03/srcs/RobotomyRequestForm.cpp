#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <unistd.h>
#include <exception>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("robotomy request", 72, 45),
	  target("nobody") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("robotomy request", 72, 45),
	  target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::srand(time(NULL));
	std::cout << "Whirrrr..\n";
	sleep(1);
	std::cout << "Whirrrrrrrrrrrrrrr..\n";
	sleep(1);
	std::cout << "Whir.\n";
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully!\n";
	else
		std::cout << "robotomy failed on " << target << '\n';
}
