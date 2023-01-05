#include "process.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <stdio.h>
#include <python3.10/Python.h>

void Stack_::putOnStack(int coming_time, int executing_time)
{
    Stack.push_back({temp_num, coming_time, executing_time});
    temp_num++;
}

void Stack_::fetchFromUser()
{
    int num_of_process = 0;
    int i = 0;
    while (i == 0)
    {
        int coming_time, executing_time;
        coming_time = 0;
        if (num_of_process == 0)
        {
            std::cout << "Proces 1 zawsze przychodzi z czasem wejścia równym zero 0.\n";
        }
        else
        {
            std::cout << "Podaj czas przyjścia procesu " << num_of_process + 1 << ": ";
            std::cin >> coming_time;
        }
        if (coming_time == 9999)
        {
            i = 1;
        }
        std::cout << "Podaj czas trwania procesu " << num_of_process + 1 << ": ";
        std::cin >> executing_time;
        putOnStack(coming_time, executing_time);
        num_of_process++;
    }
}

void Stack_::fetchFromRand()
{
    char filename[] = "generator.py";
    FILE* fp;
    
    Py_Initialize();

    fp = fopen(filename, "r");
    PyRun_SimpleFile(fp, filename);

    Py_Finalize();
    
    std::fstream file_with_processes;
    file_with_processes.open("files/generated_processes.txt", std::ios::in);
    int file_coming, file_executing;
    while (file_with_processes >> file_coming >> file_executing)
    {
        putOnStack(file_coming, file_executing);
    }
    file_with_processes.close();
    Stack.at(0).coming_time = 0;
}

void Stack_::fetchFromFile()
{
    std::fstream file_with_processes;
    file_with_processes.open("files/sample_processes.txt", std::ios::in);
    if (!file_with_processes)
    {
        std::cout << "Plik z danymi powinien zostac załączony do folderu 'files' z programem!";
    }
    else
    {
        int file_coming, file_executing;
        while (file_with_processes >> file_coming >> file_executing)
        {
            putOnStack(file_coming, file_executing);
        }
    }
    file_with_processes.close();
    Stack.at(0).coming_time = 0;
}

void Stack_::debugDisplay()
{
    for (auto i = 0; i < (int) Stack.size(); i++)
    {
        std::cout << "Proces " << Stack.at(i).id << ":\nCzas przyjścia: " << Stack.at(i).coming_time << "\nCzas trwania: " << Stack.at(i).executing_time << "\n"; 
    }
}