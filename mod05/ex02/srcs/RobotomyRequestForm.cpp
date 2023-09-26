#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <exception>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45),
	  target("nobody") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request", 72, 45),
	  target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::srand(time(NULL));
	std::cout << "Whirrrr..\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Whirrrrrrrrrrrrrrr..\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Whir.\n";
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully!\n";
	else
	{
		std::cout << "robotomy failed on " << target << '\n';
		throw std::runtime_error("robotomy failed on " + target);
	}
}
