#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
int main() {
    try {
        Bureaucrat *bureaucrat = new Bureaucrat("John", 138);
        // std::cout << bureaucrat->getName() << std::endl;
        // std::cout << *bureaucrat << std::endl;

        ShrubberyCreationForm *form = new ShrubberyCreationForm("home");
        // std::cout << *form << std::endl;

        bureaucrat->signForm(*form);
        bureaucrat->executeForm(*form);
        // form->execute(*bureaucrat);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

