#pragma once

#include <iostream>
#include "AForm.hpp"


class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

        void execute(Bureaucrat const &executor) const;

    private:
        std::string const _target;
};