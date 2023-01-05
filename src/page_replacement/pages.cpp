#include "pages.hpp"
#include <fstream>
#include <iostream>
#include <python3.10/Python.h>

void Pages_::putOnStack(int id)
{
    Pages.push_back({id});
}

void Pages_::fetchFromRand()
{
    std::fstream file_with_pages;
    file_with_pages.open("files/generated_pages.txt", std::ios::in);
    int id;
    while (file_with_pages >> id)
    {
        putOnStack(id);
    }
    file_with_pages.close();
}

void Pages_::fetchFromFile()
{
    std::fstream file_with_pages;
    file_with_pages.open("files/sample_pages.txt", std::ios::in);
    if (!file_with_pages)
    {
        std::cout << "Plik z danymi powinien zostać załączony do foleru files!";
    }
    else
    {
        int id;
        while (file_with_pages >> id)
        {
            putOnStack(id);
        }
    }
    file_with_pages.close();
}

void Pages_::fetchFromUser()
{
    std::cout << "Podaj ile stron chcesz wprowadzić: ";
    int num;
    int temp = 1;
    int id;
    std::cin >> num;
    while (num > 0)
    {
        std::cout << "Podaj identyfikator strony " << temp << ": ";
        std::cin >> id;
        temp++;
        num--;
        putOnStack(id);
    }
}