#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

#include <sys/time.h>
#include <cctype>

std::list<std::pair<int, int> > listSort(std::string str);
std::vector<std::pair<int, int> > vectorSort(std::string str);


template <typename T>
int initializeContainer(T& ct, std::string s)
{
    std::string digits("0123456789");
    int first = -1;
    int second = -1;

    size_t i = s.find_first_of(digits);
    while (i != std::string::npos)
    {
        if (first == -1)
            first = atoi(s.substr(i, s.find_first_of(" ", i) - i).c_str());
        else if (second == -1)
            second = atoi(s.substr(i, s.find_first_of(" ", i) - i).c_str());
        else
        {
            if (first < second)
                ct.push_back(std::make_pair(first, second));
            else
                ct.push_back(std::make_pair(second, first));
            first = second = -1;
            continue;
        }
        i = s.find_first_of(digits, s.find_first_of(" ,", i));
    }
    if (first != -1 && second != -1)
    {
        if (first < second)
            ct.push_back(std::make_pair(first, second));
        else
            ct.push_back(std::make_pair(second, first));
    }
    else if (first != -1)
        return first;
    return (-1);
}
