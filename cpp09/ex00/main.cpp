#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    std::ifstream f(argv[1]);
    if (f.fail())
    {
        std::cerr << "Error opening the file" << std::endl;
        return (1);
    }
    BitcoinExchange bitcoinExchange;
    bitcoinExchange.pathFile = argv[1];
    bitcoinExchange.dataInsert("data.csv");
    bitcoinExchange.getExchange(f);

    return 0;
}
