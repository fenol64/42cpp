#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (*++argv)
    {
        for (int i = 0; (*argv)[i]; i++)
            std::cout << (char)toupper((*argv)[i]);
    }
    std::cout << std::endl;
    return 0;
}