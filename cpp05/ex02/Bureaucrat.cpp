#include <iostream>
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
    if (this != &src) {
        _grade = src._grade;
    }
    return *this;
}

std::string const &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }

}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}