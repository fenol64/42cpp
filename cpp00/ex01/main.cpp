#include <iostream>
#include "PhoneBook/PhoneBook.hpp"

int main ()
{
    PhoneBook phonebook = PhoneBook();

    std::string input;
    while (1) {
        std::cout << "Enter command: ";
        std::cin >> input;
        if (input == "EXIT") {
            break;
        } else if (input == "ADD") {
            phonebook.add_contact();
        } else if (input == "SEARCH") {
            phonebook.search_contact();
        } else if (input == "PRINT") {
            phonebook.print_contacts();
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
    return 0;
}