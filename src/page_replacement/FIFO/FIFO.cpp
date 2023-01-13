#include "FIFO.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>

void FIFO::FIFO_checkFaults()
{
    std::vector<int> q;
    std::fstream outdata;
    outdata.open("files/running_log.txt", std::ios_base::app);
    outdata << "\n\n\n---------------------------------\nFIFO:";

    for (int i = 0; i < (int) _stack.size(); i++)
    {
        if (std::count(q.begin(), q.end(), _stack.at(i)))
        {
            std::cout << "\nPage " << _stack.at(i) << " already in cache";
            outdata << "\nPage " << _stack.at(i) << " already in cache";
        }
        else
        {

            if ((int) q.size() == size)
            {
                q.erase(q.begin());
                q.push_back(_stack.at(i));
                faults++;
                std::cout << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame exceeded";
                outdata << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame exceeded";
            }
            else
            {
                q.push_back(_stack.at(i));
                std::cout << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame not exceeded";
                outdata << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame not exceeded"    ;
                faults++;
            }
        }
    }
}

void FIFO::results()
{
    FIFO_checkFaults();
    std::cout << "\nLiczba wystąpień błędów w algortymie FIFO: " << faults << "\n";
    std::fstream outdata;
    outdata.open("files/running_log.txt", std::ios_base::app);
    outdata << "\nLiczba wystąpień błędów w algortymie FIFO: " << faults << "\n";
    outdata.close();
}