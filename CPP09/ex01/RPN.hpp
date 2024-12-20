#pragma once

#include <string>
#include <fstream>
#include <stack>
#include <iostream>
#include <stdlib.h>

using namespace std;

class RPN
{
    private:
        std::stack<int> stack;
        int one;
        int two;
        int result;

    public:
    RPN();
    int setAlgorithm(std::string &expression);
    const std::stack<int> &getStack() const;
    int getResult();
    int doOperation(char op);
    char isOperator (std::string a);
    int isNumber (std::string a);
    string isNegative(string token);

};