#include "PmergeMe.hpp"

static std::string getNbrs(char *argv[]);
static void firstSort(std::string number);
static void secondSort(std::string number);


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    std::string number = getNbrs(argv);
    if (number == "-1")
        return (0);
    std::cout << "Before:\t" << number << std::endl;
    std::cout << "After:\t";
    firstSort(number);
    secondSort(number);
    return (0);
}

static std::string getNbrs (char *argv[])
{
    std::string result;

    for (size_t i = 1; argv[i] !=  NULL; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (argv[i][j] == '-')
            {
                std::cerr << "Invalid '-' char" << std::endl;
                return ("-1");
            }
            if (!isdigit(argv[i][j]) && !isspace(argv[i][j]))
            {
                std::cerr << "Invalid input. Only accepting positive intergers" << std::endl;
                return ("-1");
            }
            if(std::isdigit(argv[i][j]))
            {
                result += argv[i][j];
                if (!isdigit(argv[i][j + 1]))
                    result += " ";
            }
        }
    }
        return (result);
}

static void firstSort(std::string number)
{
    std::vector<std::pair<int, int> > result;
    timeval start, end;
    double span;

    gettimeofday(&start, NULL);
    result = vectorSort(number);
    gettimeofday(&end, NULL);
    span = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    std::cout << "Time to process a range of " << result.size() << " elements with std::vector : " << span << "us" << std::endl;
}

static void secondSort(std::string number)
{
    std::list<std::pair<int, int> > result;
    timeval start, end;
    double span;

    gettimeofday(&start, NULL);
    result = listSort(number);
    gettimeofday(&end, NULL);
    span = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    std::cout << "Time to process a range of " << result.size() << " elements with std::list : " << span << "us" << std::endl;
}




