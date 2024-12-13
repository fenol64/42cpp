
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(src._signed) {}

Form::~Form() {}

Form &Form::operator=(Form const &src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return *this;
}

std::string const &Form::getName() const {
    return _name;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

bool Form::isSigned() const {
    return _signed;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, Form const &form) {
    os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form is " << (form.isSigned() ? "" : "not ") << "signed";
    return os;
}

const char * Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char * Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

