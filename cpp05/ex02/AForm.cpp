
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(src._signed) {}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return *this;
}

std::string const &AForm::getName() const {
    return _name;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

bool AForm::isSigned() const {
    return _signed;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, AForm const &form) {
    os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form is " << (form.isSigned() ? "" : "not ") << "signed";
    return os;
}

const char * AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

