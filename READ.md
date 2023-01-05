# Projekt na zaliczenie kursu SO
Projekt zawiera w sobie algorytmy FCFS i LCFS zawrte w osobnych modułach programu. Zostały również zaimplementowane algortymy zamiany stron FIFO i LRU. Wszystkie moduły nadzorowane są przez moduł "advisor".

### W celu skorzystania z danych z pliku, dołącz plik w formacie .txt o nazwie "sample_processes" do folderu "files" z programem
W pliku powinny zostać zawarte:
- w pierwszej kolumnie czas przybycia procesu (proces 0 ma ignorowany czas)
- po spacji w drugiej kolumnie czas wykonania procesu

#### To samo dotyczy algorytmu zamiany stron, jednak nazwa pliku to "sample_pages.txt"
W pliku powinny zostać zawarte:
- Numery id poszczególnych stron

Aby zmienić sposób odczytu z pliku sprawdź 'advior.cpp'.


## W folderze z programem zawarty jest skrypt generator.py, który generuje (automatycznie z poziomu Projektu) dane oraz automatycznie je zapisuje
Generator tworzy czasy przyjścia oraz czasy wykonywania procesów odpowiednio z rozkładu normalnego oraz rozkładu uniform.

### Użyte biblioteki
- python3.10-dev
- fstream
- vector
- algorithm
- boost
##### Aby uruchomić program wymagany jest python3.10-dev (wymaga aktualizacja ścieżki nagłówka Python.h w pliku process.cpp), pozostałe biblioteki są dostarczone z kompilatorem/programem