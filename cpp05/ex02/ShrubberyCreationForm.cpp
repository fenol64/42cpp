#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::ofstream file(_target + "_shrubbery");
    if (!file.is_open())
        throw std::runtime_error("Cannot open file");
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file.close();
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &form) {
    os << "Form " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return os;
}