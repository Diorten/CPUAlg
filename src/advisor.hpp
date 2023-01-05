#pragma once
//hope
#include "processor_planning/process.hpp"
#include "page_replacement/pages.hpp"

class Advisor
{
    private:
    Stack_ stack;
    Pages_ pages;
    int opt_3;

    public:
    void fetchInfo();
    void initRun(int opt);
    void startAlgorithms();
    void manage();
};