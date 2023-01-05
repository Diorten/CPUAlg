#pragma once
#include <vector>

class Pages_
{
private:
    void putOnStack(int id);

public:
    std::vector <int> Pages;
    void fetchFromRand();
    void fetchFromFile();
    void fetchFromUser();
};