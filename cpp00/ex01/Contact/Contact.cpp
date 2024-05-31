#include <iostream>
#include "Contact.hpp"

Contact::Contact() {
    this->name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::~Contact() {}


void Contact::set_name(std::string name) {
    this->name = name;
}

void Contact::set_last_name(std::string last_name) {
    this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname) {
    this->nickname = nickname;
}

void Contact::set_phone_number(std::string phone_number) {
    this->phone_number = phone_number;
}

void Contact::set_darkest_secret(std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}

std::string Contact::get_name() {
    return this->name;
}

std::string Contact::get_last_name() {
    return this->last_name;
}

std::string Contact::get_nickname() {
    return this->nickname;
}

std::string Contact::get_phone_number() {
    return this->phone_number;
}

std::string Contact::get_darkest_secret() {
    return this->darkest_secret;
}

void Contact::create_contact() {
    std::string name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter name: ";
    std::cin >> name;
    this->set_name(name);
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    this->set_last_name(last_name);
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    this->set_nickname(nickname);
    std::cout << "Enter phone number: ";
    std::cin >> phone_number;
    this->set_phone_number(phone_number);
    std::cout << "Enter darkest secret: ";
    std::cin >> darkest_secret;
    this->set_darkest_secret(darkest_secret);
}

void Contact::print_contact() {
    std::cout << "name: " << this->name << std::endl;
    std::cout << "last name: " << this->last_name << std::endl;
    std::cout << "nickname: " << this->nickname << std::endl;
    std::cout << "phone number: " << this->phone_number << std::endl;
    std::cout << "darkest secret: " << this->darkest_secret << std::endl;
}
