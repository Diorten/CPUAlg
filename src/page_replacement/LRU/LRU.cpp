#include "LRU.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <boost/bind/bind.hpp>

struct PageStruct
{
    int id;
    int last_usage;
};

void LRU::LRU_checkFaults()
{
    std::vector<PageStruct> q;
    std::fstream outdata;
    outdata.open("files/running_log.txt", std::ios_base::app);
    outdata << "\n\nLRU:";

    for (int i = 0; i < (int) _stack.size(); i++)
    {
        for (int k = 0; k < (int) q.size(); k++)
        {
            //std::cout << "\n" << q.at(k).id;
            q.at(k).last_usage++;
        }
        auto it = std::find_if(q.begin(), q.end(), boost::bind(&PageStruct::id, boost::placeholders::_1) ==_stack.at(i));
        if (it != q.end())
        {
            int temp_id = std::distance(q.begin(), it);
            q.at(temp_id).last_usage = 0;
            std::cout << "\nPage " << _stack.at(i) << " already in cache";
            outdata << "\nPage " << _stack.at(i) << " already in cache";
        }
        else
        {
            if ((int) q.size() == size)
            {
                int temp_id = 0;
                for (int j = 0; j < (int) q.size(); j++)
                {
                    if (q.at(j).last_usage > q.at(temp_id).last_usage)
                    {
                        temp_id = j;
                    }
                }
                q.at(temp_id).id = _stack.at(i);
                q.at(temp_id).last_usage = 0;
                std::cout << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame exceeded";
                outdata << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame exceeded";
                faults++;
            }
            else
            {
                q.push_back({_stack.at(i), 0});
                std::cout << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame not exceeded";
                outdata << "\nPage " << _stack.at(i) << " couldn't be found in cache, size of frame not exceeded";
                faults++;
            }
        }
    }
}

void LRU::results()
{
    LRU_checkFaults();
    std::cout << "\nLiczba wystąpień błędów w algortymie LRU: " << faults << "\n";
    std::fstream outdata;
    outdata.open("files/running_log.txt", std::ios_base::app);
    outdata << "\nLiczba wystąpień błędów w algortymie LRU: " << faults << "\n";
    outdata.close();
}