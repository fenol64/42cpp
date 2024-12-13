#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	AForm::operator=(src);
	return *this;
}

void RobotomyRequestForm::action(void) const {
	std::cout << "*drilling noises* ";
	if (rand() % 2) {
		std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << this->getName() << " robotomization failed" << std::endl;
	}
}