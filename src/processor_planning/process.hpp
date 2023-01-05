#pragma once
#include <vector>


struct ProcessStruct
{
    int id;
    int coming_time;
    int executing_time;
    int waiting_time;
    int execute = 0;
};

class Stack_
{
    private:
    int temp_num = 1;
    void putOnStack(int coming_time, int executing_time);

    public:
    std::vector<ProcessStruct> Stack;

    void debugDisplay();
    void fetchFromRand();
    void fetchFromFile();
    void fetchFromUser();
};