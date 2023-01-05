import numpy as np

norm_nums = [np.random.normal(2000, 200) for _ in range(20)]
uniform_nums = [np.random.uniform(1000, 100) for _  in range(20)]
uniform_nums_2 = [np.random.uniform(10, 1) for _  in range(20)]


with open('files/generated_pages.txt', 'w') as fp:
    for id in range(20):
        formatted_number_u2 = "{:.0f}".format(uniform_nums_2[id])
        fp.write(str(formatted_number_u2) + '\n')

with open('files/generated_processes.txt', 'w') as f:
    for id in range(20):
        formatted_number_u = "{:.0f}".format(uniform_nums[id])
        formatted_numbe_n = "{:.0f}".format(norm_nums[id])
        f.write(str(formatted_number_u) + '\t' + str(formatted_numbe_n) + '\n')
        
#def generate_processes(num_processes,m1,sd1,l,h):
    # Używamy rozkładu normalnego z średnią m i odchyleniem standardowym sd
    # dla przybycia procesów i trwania procesów

 #   for i in range(num_processes):
        # Losujemy przybycie procesu z rozkładu normalnego
  #      czas_przyjscia = np.random.uniform(l, h)
        # Losujemy trwanie procesu z rozkładu normalnego
   #     czas_trwania = np.random.normal(m1,sd1)
        # Tworzymy obiekt procesu
        #p = klasa.Procesy(f"Process {i + 1}", czas_przyjscia, czas_trwania)
        # Dodajemy proces do listy
        #processes.append(p)

    #return processes

#def save_processes(processes, filename):
 #   with open(filename, "w") as f:
  #      for p in processes:
   #         f.write(f"{p.nazwa},{p.czas_przyjscia},{p.czas_trwania}\n")

#def load_processes(filename):
 #   processes = []
  #  with open(filename, "r") as f:
   #     for line in f:
    #        nazwa, czas_przyjscia, czas_trwania = line.strip().split(",")
     #       #p = klasa.Procesy(nazwa, float(czas_przyjscia), float(czas_trwania))
      #      #processes.append(p)
    #return processes

#processes=generate_processes(20,20,2,10,1)
#save_processes(processes,"Dane.txt")
#processes = load_processes("Dane.txt")
#czas przybycia z rozkładu jednostajnego