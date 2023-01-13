#include "advisor.hpp"
#include <iostream>
#include "processor_planning/FCFS/FCFS.hpp"
#include "processor_planning/LCFS/LCFS.hpp"
#include "page_replacement/FIFO/FIFO.hpp"
#include "page_replacement/LRU/LRU.hpp"
#include <fstream>

void Advisor::fetchInfo()
{
    int opt;
    int temp = 0;
    do
    {
        std::cout << "Wybierz sposób wprowadzenia danych:\n[1] - wygeneruj\n[2] - wprowadź z pliku\n[3] - wprowadź ręcznie\n[4] - wyświetl informacje\n";
        std::cin >> opt;
        if (opt == 4)
        {
            system("clear");
            std::cout << "Program bada algorytmy planowania czasu procesora FCFS oraz LCFS. Algorytm FCFS jest opisany prostymi funkcjami matematycznymi pozwalającymi ";
            std::cout << "na opis algorytmu oraz uzyskanie informacji na temat czasu oczekiwania procesu i jego wykonywania.\nZaś algorytm LCFS został zaimplementowany w sposób ";
            std::cout << "symulacji rzeczywistej pracy procesora, podczas której dostaje (symulowane) procesy, oraz obsługuje je przez (zasymulowany) czas. Wszystko mierzy 'tick-timer' ";
            std::cout << "badający wewnętrzny czas procesora.\n\nProgram bada również algorytmy zamiany stron FIFO oraz LRU. Algorytm FIFO...";
            std::cout << "\n\nPliki załączone z programem:\ngenerator.py - generator danych wejściowych dla algorytmów FCFS i LCFS w języku python obługiwany automatycznie z poziomu ";
            std::cout << "tego programu\nsample_processes.txt - plik tekstowy z danymi własnymi, możemy go edytować podając dane na temat czasu przyjścia procesów oraz ich trwania";
            std::cout << "\ngenerated_processes.txt - plik tekstowy z danymi wygenerowanymi przez generator.py, aby nie utracić ich po zamknięciu aplikacji\nresults.txt - plik zapisujący wyniki ";
            std::cout << "każdego z algorytmów do dalszej analizy.\n\n";
        }
        if (opt > 0 && opt < 4)
        {
            temp++;
        }
    } while (temp != 1);
    temp = 0;
    do
    {
        std::cout << "Ostatecznie wybierz ilość ramek pamięci:\n";
        std::cin >> opt_3;
        if (opt_3 > 0)
        {
            temp++;
        }
    } while (temp != 1);
    initRun(opt);
}

void Advisor::initRun(int opt)
{
    if (opt == 1)
    {
        stack.fetchFromRand();
        pages.fetchFromRand();
    }
    else if (opt == 2)
    {
        stack.fetchFromFile();
        pages.fetchFromFile();
    }
    else
    {
        stack.fetchFromUser();
        pages.fetchFromUser();
    }
    startAlgorithms();
}

void Advisor::startAlgorithms()
{
    //stack.debugDisplay();
    FirstCome fc{stack.Stack};
    LCFS lc{stack.Stack};
    FIFO fifo{pages.Pages, opt_3};
    LRU lru{pages.Pages, opt_3};


    /// @brief ///
    std::cout << "FCFS:\n";
    fc.averageTime();
    std::cout << "\n\nLCFS:\n";
    lc.averageTime();
    std::cout << "\n\nFIFO:";
    fifo.results();
    std::cout << "\n\nLRU:";
    lru.results();
}