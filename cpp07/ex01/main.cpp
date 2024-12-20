#include "Iter.hpp"

void	toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
};

void toNegative(int &i)
{
	i = -i;
};

int main(void)
{
	char str[] = "Hello, World!";
	int array[] = {1, 2, 3, 4, 5};

	iter(str, 13, toUpper);
	iter(array, 5, toNegative);

	std::cout << str << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " ";
	return (0);
}