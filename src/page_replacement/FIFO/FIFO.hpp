#pragma once
#include "../pages.hpp"

class FIFO
{
    std::vector<int> _stack;
    int faults = 0;
    int size;

    public:
    FIFO(std::vector<int> stack, int _opt_3)
    {
        _stack = stack;
        size = _opt_3;
    };

    void FIFO_checkFaults();
    void results();
};

