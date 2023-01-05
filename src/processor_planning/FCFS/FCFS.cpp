#include "FCFS.hpp"
#include <iostream>
#include <fstream>


void FirstCome::findWaitingTtime()
{
    //Waiting time for first process is 0
    _stack.at(0).waiting_time = 0;

    for (auto i = 1; i < (int) _stack.size(); i++)
    {
        _stack.at(i).waiting_time = _stack.at(i - 1).executing_time + _stack.at(i - 1).waiting_time;
    }
}

void FirstCome::findExecutingTime()
{
    for (auto i = 0; i < (int) _stack.size(); i++)
    {
        _stack.at(i).executing_time = _stack.at(i).executing_time + _stack.at(i).coming_time + _stack.at(i).waiting_time;
    }
}

void FirstCome::averageTime()
{
    findWaitingTtime();
    findExecutingTime();

    int total_waiting_time = 0;
    int total_executing_time = 0;


    std::ofstream outdata;
    outdata.open("files/results.txt", std::ios_base::app);

    outdata << "FCFS:\n";
    for (auto i = 0; i < (int) _stack.size(); i++)
    {
        total_waiting_time = total_waiting_time + _stack.at(i).waiting_time;
        total_executing_time = total_executing_time + _stack.at(i).executing_time;
        std::cout << "Process " << _stack.at(i).id << " finished, waiting time: " << _stack.at(i).waiting_time << ", executing time: " << _stack.at(i).executing_time << "\n";
        outdata << "Process " << _stack.at(i).id << " finished, waiting time: " << _stack.at(i).waiting_time << ", executing time: " << _stack.at(i).executing_time << "\n";
    }

    std::cout << "Średni czas oczekiwania procesu: " << (float) total_waiting_time/ (float) _stack.size() << "\n";
    std::cout << "Średni czas wykonywania procesu: " << (float) total_executing_time/ (float) _stack.size() << "\n";
    outdata << "Średni czas oczekiwania procesu: " << (float) total_waiting_time/ (float) _stack.size() << "\n" << "Średni czas wykonywania procesu: " << (float) total_executing_time/ (float) _stack.size() << "\n";
    
    outdata.close();
}
