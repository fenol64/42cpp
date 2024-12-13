#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
int main() {

    Bureaucrat *bureaucrat = new Bureaucrat("John", 2);
    std::cout << bureaucrat->getName() << std::endl;
    std::cout << *bureaucrat << std::endl;

    ShrubberyCreationForm *form = new ShrubberyCreationForm("home");
    std::cout << *form << std::endl;

    bureaucrat->signForm(*form);
    form->execute(*bureaucrat);


    return 0;
}

