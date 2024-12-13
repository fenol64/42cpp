#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);

		Intern &operator=(const Intern &src);

		AForm *makeForm(std::string form, std::string target);

		class InvalidFormsNameException: public std::exception {
			public:
				const char *what() const throw();
		};
};