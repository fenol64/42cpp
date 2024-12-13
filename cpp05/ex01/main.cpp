#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    Bureaucrat *bureaucrat = new Bureaucrat("John", 2);
    std::cout << bureaucrat->getName() << std::endl;
    std::cout << *bureaucrat << std::endl;

    return 0;
}

