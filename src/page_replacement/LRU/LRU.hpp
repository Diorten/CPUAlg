#pragma once
#include "../pages.hpp"

class LRU
{
    std::vector<int> _stack;
    int faults = 0;
    int size;

    public:
    LRU(std::vector<int> stack, int _opt_3)
    {
        _stack = stack;
        size = _opt_3;
    };

    void LRU_checkFaults();
    void results();
};

