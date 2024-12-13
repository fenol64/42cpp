#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

        void execute(Bureaucrat const &executor) const;

    private:
        std::string const _target;
};