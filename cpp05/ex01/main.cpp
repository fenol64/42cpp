#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat *bureaucrat = new Bureaucrat("John", 5);
        Form form("Form1", 5, 10);
        std::cout << bureaucrat->getName() << std::endl;
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->signForm(form);
        std::cout << *bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

