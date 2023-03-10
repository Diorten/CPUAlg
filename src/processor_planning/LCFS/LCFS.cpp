#include "LCFS.hpp"
#include <iostream>
#include <fstream>


void LCFS::emulator()
{
    std::ofstream outdata;
    outdata.open("files/running_log.txt", std::ios_base::app);

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
    outdata.open("files/running_log.txt", std::ios_base::app);

    emulator();
    findWaitingTime();
    findExecutingTime();
    std::cout << "??redni czas oczekiwania procesu: " << average_wait << "\n";
    std::cout << "??redni czas wykonywania procesu: " << average_exec << "\n";

    outdata << "??redni czas oczekiwania procesu: " << average_wait << "\n" << "??redni czas wykonywania procesu: " << average_exec << "\n";
    outdata.close();

    int temp_wt;

    for (int i = 0; i < (int) _stack.size(); i++)
    {
        _stack.at(i).waiting_time = _stack.at(i).execute - _stack.at(i).executing_time;
    }
    
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        for (int j = 0; j < (int) _stack.size(); j++)
        {
            if (_stack.at(i).waiting_time < _stack.at(j).waiting_time)
            {
                temp_wt = _stack.at(i).waiting_time;
                _stack.at(i).waiting_time = _stack.at(j).waiting_time;
                _stack.at(j).waiting_time = temp_wt;
            }
        }
    }

    outdata.open("files/background_files/out_wts_l.txt");
    for (int i = 0; i < (int) _stack.size(); i++)
    {
        outdata << _stack.at(i).waiting_time << "\n";
    }
    outdata.close();
}
