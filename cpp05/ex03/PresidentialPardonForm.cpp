#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	AForm::operator=(src);
	return *this;
}

void PresidentialPardonForm::action(void) const {
	std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}