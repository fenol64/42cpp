#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat();
        Bureaucrat &operator=(Bureaucrat const &src);

        std::string const &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form) const;


    private:
        std::string const _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);
