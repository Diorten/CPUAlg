default: build

build:
	g++ -Wall -o Projekt src/main.cpp src/processor_planning/process.cpp src/advisor.cpp src/page_replacement/pages.cpp src/processor_planning/FCFS/FCFS.cpp src/processor_planning/LCFS/LCFS.cpp src/page_replacement/FIFO/FIFO.cpp src/page_replacement/LRU/LRU.cpp -lpython3.10