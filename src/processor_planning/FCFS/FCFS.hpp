#pragma once
#include "../process.hpp"

class FirstCome
{
    std::vector<ProcessStruct> _stack;

    public:
    FirstCome(std::vector<ProcessStruct> stack)
    {
        _stack = stack;
    };
    void findWaitingTtime();
    void findExecutingTime();
    void averageTime();
};