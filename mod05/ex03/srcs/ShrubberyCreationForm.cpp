#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("shrubbery creation", 145, 137),
	  target("nobody") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("shrubbery creation", 145, 137),
	  target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	std::ofstream outfile(target + "_shrubbery");
	if (outfile)
	{
		outfile << ""
				<< "               ,@@@@@@@,\n"
				<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
				<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
				<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
				<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
				<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
				<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
				<< "       |o|        | |         | |\n"
				<< "       |.|        | |         | |\n"
				<< "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"
				<< "\n"
				<< "- Nature\n";
		outfile.close();
	}
	else
		std::cerr << "Action on file " << target << "_shrubbery isn't possible.\n";
}
