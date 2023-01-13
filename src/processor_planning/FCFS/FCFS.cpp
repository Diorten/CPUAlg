#include "FCFS.hpp"
#include <iostream>
#include <fstream>


void FirstCome::findWaitingTtime()
{
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        for (int j = 0; j < (int) _stack.size(); j++)
        {
            if (_stack.at(i).coming_time < _stack.at(j).coming_time)
            {
                int temp_incoming = _stack.at(j).coming_time;
                int temp_executing = _stack.at(j).executing_time;
                int temp_id = _stack.at(j).id;
                _stack.at(j) = _stack.at(i);
                _stack.at(i).id = temp_id;
                _stack.at(i).coming_time = temp_incoming;
                _stack.at(i).executing_time = temp_executing;
            }
        }
    }
    /*
    for (int i = 1; i < (int) _stack.size(); i++)
    {
        _stack.at(i).coming_time -= _stack.at(0).coming_time;
    }
    */
    _stack.at(0).coming_time = 0;
    
    /*
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        std::cout << _stack.at(i).coming_time << " " << _stack.at(i).executing_time << "\n";
    }
    */
    
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
    outdata.open("files/running_log.txt", std::ios_base::app);

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

    outdata.open("files/background_files/out_wts_f.txt");
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        outdata << _stack.at(i).waiting_time << "\n";
    }
    outdata.close();
}
