#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &form) {
    os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form is " << (form.isSigned() ? "" : "not ") << "signed";
    return os;
}