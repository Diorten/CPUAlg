#pragma once
#include "../process.hpp"

class LCFS
{
    std::vector<ProcessStruct> _stack;
//    std::vector <int> av_exec;


    public:
    LCFS(std::vector<ProcessStruct> stack)
    {
        _stack = stack;
    };

    int already_finished = 0;
    int tick_timer = 0;
    float average_exec = 0;
    float average_wait = 0;
    void emulator();
    void findExecutingTime();
    void findWaitingTime();
    void averageTime();

};