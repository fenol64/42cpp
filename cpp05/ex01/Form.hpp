#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        ~Form();
        Form &operator=(Form const &src);

        std::string const &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        void beSigned(Bureaucrat const &bureaucrat);

    private:
        std::string const _name;
        int const _gradeToSign;
        int const _gradeToExecute;
        bool _signed;
};

std::ostream &operator<<(std::ostream &os, Form const &form);