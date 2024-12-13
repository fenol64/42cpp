#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Pablito", 145, 137)
{
	std::cout << "Default Contructor Calling" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	std::cout << "Params Contructor Calling" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout << "Copy Contructor Calling" << std::endl;
	*this = copy;
};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		this->setSign(src.getSign());
	}
	return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor ShrubberyCreationForm Calling" << std::endl;
};

void ShrubberyCreationForm::action(void) const
{
	std::ofstream file((this->getName() + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "      /\\      " << std::endl;
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file.close();
	}
	else
		std::cout << "Error: Could not open file" << std::endl;
};