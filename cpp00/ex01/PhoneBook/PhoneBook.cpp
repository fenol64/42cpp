#include <iostream>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->contacts_count = 0;
    this->index = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact() {
    if (this->index == 8)
        this->index = 0;
    if (this->index < 8) {
        this->contacts[this->index].create_contact();
        this->index++;
    }
    if (this->contacts_count < 8)
        this->contacts_count++;
    
}

void PhoneBook::search_contact() {
    int index;
    std::string input;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < this->contacts_count; i++) {
        std::cout << "         " << i << "|";
        std::cout.width(10);
        std::cout << this->contacts[i].get_name() << "|";
        std::cout.width(10);
        std::cout << this->contacts[i].get_last_name() << "|";
        std::cout.width(10);
        std::cout << this->contacts[i].get_nickname() << std::endl;
    }
    std::cout << "Enter index: ";
    std::cin >> input;
    index = atoi(input.c_str());
    if (index >= 0 && index < this->contacts_count) {
        this->contacts[index].print_contact();
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void PhoneBook::print_contacts() {
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < this->contacts_count; i++) {
        std::cout << "         " << i << "|";
        std::cout.width(10);
        std::cout << this->contacts[i].get_name() << "|";
        std::cout.width(10);
        std::cout << this->contacts[i].get_last_name() << "|";
        std::cout.width(10);
        std::cout << this->contacts[i].get_nickname() << std::endl;
    }
}


