#include "Intern.hpp"

Intern::Intern(void) {
};

Intern::Intern(const Intern &copy) {
	*this = copy;
};

Intern::~Intern(void) {
};

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
};

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *result = 0;

	std::string	sheets[3] = {"Presidential pardon", "Robotomy request", "Shrubbery creation" };

	try
	{
		int i;
		for (i = 0; i < 3; i++)
			if (sheets[i] == name)
				break ;
		switch (i)
		{
		case 0:
			result = new PresidentialPardonForm(target);
			break;
		case 1:
			result = new RobotomyRequestForm(target);
			break;
		case 2:
			result = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::InvalidFormsNameException();
		}
		std::cout << "intern creates " << name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return result;
}

char const *Intern::InvalidFormsNameException::what() const throw()
{
	return "Invalid Forms name. Please insert right names ok?";
};