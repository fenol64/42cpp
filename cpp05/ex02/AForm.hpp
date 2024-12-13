#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm {
    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        AForm(std::string const &name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &src);
        virtual ~AForm();

        AForm &operator=(AForm const &src);

        std::string const &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        void beSigned(Bureaucrat const &bureaucrat);
        void execute(Bureaucrat const &executor) const;


    private:
        std::string const _name;
        int const _gradeToSign;
        int const _gradeToExecute;
        bool _signed;
};

std::ostream &operator<<(std::ostream &os, AForm const &form);