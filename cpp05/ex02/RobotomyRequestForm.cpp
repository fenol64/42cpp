#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << "*drilling noises* ";
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &form) {
    os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form is " << (form.isSigned() ? "" : "not ") << "signed";
    return os;
}
