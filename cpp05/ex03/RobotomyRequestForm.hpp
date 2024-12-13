#pragma once
#include "AForm.hpp"
#include <cstdlib>


class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		void action(void) const;
};