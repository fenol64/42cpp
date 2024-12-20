#include <iostream>
#include "Array.hpp"

int main(void)
{
    Array<int> a(5);
    Array<int> b(5);
    Array<int> c(5);

    for (unsigned int i = 0; i < 5; i++)
    {
        a[i] = i;
        b[i] = i + 1;
        c[i] = i;
    }

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;

    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    return (0);
}
