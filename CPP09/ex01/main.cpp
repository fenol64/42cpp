#include "RPN.hpp"

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    RPN rpn;
    if (argc != 2)
    {
        std::cerr << "Invalid args" << std::endl;
        return -1;
    }
    while (argv[i][j])
    {
        if (!isdigit(argv[i][j]) && argv[i][j] != ' ' && argv[i][j] != '\t'
            && argv[i][j] != '*' && argv[i][j] != '/' && argv[i][j] != '+' && argv[i][j] != '-')
        {
            std::cerr << "Invalid args" << std::endl;
            return (-1);
        }
        j++;
    }
    std::string str = argv[1];
    rpn.setAlgorithm(str);
    // std::cout << rpn.getResult() << std::endl;
}
