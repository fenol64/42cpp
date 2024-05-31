#include "../Contact/Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contacts_count;
        int index;
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        void search_contact();
        void print_contacts();
};