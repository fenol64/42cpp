#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string param = argv[1];
		ScalarConverter::convert(param);
		return (0);
	}
	else
		std::cout << "./convert [value] only please!" << std::endl;
	return (1);
}