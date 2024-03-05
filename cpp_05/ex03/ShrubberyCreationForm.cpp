#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor has been called and types have been set!" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &in) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = in; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &in)
{
	if (this == &in)
	{
		return (*this);
	}
	this->_target = in._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor is called!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned() != true)
			throw (AForm::FormSignedFalseException());
		if (executor.getGrade() > this->getExecGrade())
			throw (AForm::FormBureauExecException());
	}
	catch(const std::exception& e)
	{
		std::cout << "ShrubberyCreationForm exception caught!" << std::endl;
		std::cerr << e.what() << '\n';
		return ;
	}
	std::string outfile_name = this->_target + "_shrubbery";
	std::ofstream outfile;
	outfile.open(outfile_name.c_str(), std::ios::out);
	if (this->getSigned() == true && executor.getGrade() < this->getExecGrade())
	{
		outfile << "               ,@@@@@@@," << std::endl;
		outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888/88/8o" << std::endl;
		outfile << "   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'" << std::endl;
		outfile << "   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'" << std::endl;
		outfile << "   %&&%/ %&%%&&@@/ V /@@' `88/8 `/88'" << std::endl;
		outfile << "   %&&%/ %&%%&&@@/ V /@@' `88/8 `/88'" << std::endl;
		outfile << "   `&%/ ` /%&'    |.|        / '|8'" << std::endl;
		outfile << "       |o|        | |         | " << std::endl;
		outfile << "       |.|        | |         | |" << std::endl;
		outfile << "    // ._///_/__/  ,/_//__//.  /_//__/_" << std::endl;
		outfile << "-----------------------------------------" << std::endl;
	}
	outfile.close();
	std::cout << "Shrubbery is placed at: " << outfile_name << std::endl;
}

//                ,@@@@@@@,
//        ,,,.   ,@@@@@@/@@,  .oo8888o.
//     ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
//    ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
//    %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
//    %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
//    `&%\ ` /%&'    |.|        \ '|8'
//        |o|        | |         | |
//        |.|        | |         | |
// jgs \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_