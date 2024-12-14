#include <iostream>

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat *bureaucrat = new Bureaucrat("John", -20);
        std::cout << bureaucrat->getName() << std::endl;
        std::cout << *bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

