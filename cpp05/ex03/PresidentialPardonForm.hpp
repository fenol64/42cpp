#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		void action(void) const;
};