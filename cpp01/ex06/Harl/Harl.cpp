#include "Harl.hpp"


void Harl::debug(void) {
    std::cout << "DEBUG: This is a debug message." << std::endl;
}

void Harl::info(void) {
    std::cout << "INFO: This is an info message." << std::endl;
}

void Harl::warning(void) {
    std::cout << "WARNING: This is a warning message." << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR: This is an error message." << std::endl;
}

void Harl::complain(std::string level) {
    void (Harl::*methods[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++) {
        switch(level.compare(levels[i])) {
            case 0:
                (this->*methods[i])();
                return;
        }
    }
}