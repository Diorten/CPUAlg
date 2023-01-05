#include "LCFS.hpp"
#include <iostream>
#include <fstream>


void LCFS::emulator()
{
    std::ofstream outdata;
    outdata.open("files/results.txt", std::ios_base::app);

    outdata << "\n\nLCFS:\n";
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        _stack.at(i).waiting_time = _stack.at(i).executing_time;
    }
    std::vector <int> id_queue;
    while (already_finished != (int) _stack.size())
    {
        for (int i = 0; i < (int) _stack.size(); i++)
        {
            if (tick_timer == _stack.at(i).coming_time)
            {
                if (_stack.at(i).executing_time == 0)
                {
                    std::cout << "Process " << _stack.at(i).id << " finished!\n";
                    already_finished++;
                }
                else 
                {
                    id_queue.push_back(i);
                }
            }
        }
        if (id_queue.size() > 0)
        {
            _stack.at(id_queue.back()).waiting_time -= 1;
            for (int i = 0; i < (int) id_queue.size(); i++)
            {
                _stack.at(id_queue.at(i)).execute++;
            }
            if (_stack.at(id_queue.back()).waiting_time == 0)
            {
                std::cout << "Process " << _stack.at(id_queue.back()).id << " finished, waiting time: " << (_stack.at(id_queue.back()).execute - _stack.at(id_queue.back()).executing_time) << ", executing time: " << _stack.at(id_queue.back()).execute << "\n";
                outdata << "Process " << _stack.at(id_queue.back()).id << " finished, waiting time: " << (_stack.at(id_queue.back()).execute - _stack.at(id_queue.back()).executing_time) << ", executing time: " << _stack.at(id_queue.back()).execute << "\n";

                already_finished++;
                id_queue.pop_back();
            }
            //std::cout << _stack.at(id_queue.back()).executing_time;
        }
        tick_timer++;
    }
    tick_timer--;
    outdata.close();
}

void LCFS::findWaitingTime()
{
    float temp = 0;
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        temp+= (_stack.at(i).execute - _stack.at(i).executing_time);
    }
    average_wait = temp / (float) _stack.size();
}

void LCFS::findExecutingTime()
{
    float temp = 0;
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        temp+= _stack.at(i).execute;
    }
    average_exec = temp / (float) _stack.size();
}

void LCFS::averageTime()
{
    std::ofstream outdata;
    outdata.open("files/results.txt", std::ios_base::app);

    emulator();
    findWaitingTime();
    findExecutingTime();
    std::cout << "Średni czas oczekiwania procesu: " << average_wait << "\n";
    std::cout << "Średni czas wykonywania procesu: " << average_exec << "\n";

    outdata << "Średni czas oczekiwania procesu: " << average_wait << "\n" << "Średni czas wykonywania procesu: " << average_exec << "\n";
    outdata.close();
}
