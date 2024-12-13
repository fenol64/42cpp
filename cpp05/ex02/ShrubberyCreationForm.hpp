#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

        void execute(Bureaucrat const &executor) const;

    private:
        std::string const _target;
};