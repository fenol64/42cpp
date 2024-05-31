#include <iostream>
#include "Harl/Harl.hpp"

int main (int c, char **v) {
    if (c != 2) {
        std::cout << "Usage: " << v[0] << " <level>" << std::endl;
        return 1;
    }

    std::string levels[] = {"debug", "info", "warning", "error"};
    std::string level = v[1];
    int index = -1;
    for (int i = 0; i < 4; i++) {
        switch(level.compare(levels[i])) {
            case 0:
                index = i;
                break;
        }
    }

    if (index == -1) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 1;
    }

    Harl harl;
    for (int i = index; i < 4; i++) {
        harl.complain(levels[i]);
    }
}