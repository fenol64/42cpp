#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		void action(void) const;
};