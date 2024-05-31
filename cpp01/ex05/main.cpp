#include <iostream>
#include "Harl/Harl.hpp"

int main () {
    Harl harl;
    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    return 0;
}