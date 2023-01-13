import subprocess
import numpy

# Amount of tests
quantity = 5






### Do not change values under ###
main_path = "./Projekt"
results_file = "raw_results.txt"


f = open(results_file, "a")
f.truncate(0)
f.close()

f = open ("files/results.txt", "a")
f.truncate(0)
f.close()

for i in range(quantity):
    proc = subprocess.Popen("./Projekt", stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    #Wybór opcji programu
    proc.stdin.write(b'1\n')
    proc.stdin.write(b'8\n')


    out, err= proc.communicate()
    #proc.stdin.flush()
    #output = proc.stdout.readlines()
    print (out)
    
    with open(results_file, "a") as f:
        f.write("Uruchomienie " + str(i+1) + "\n")
        f.write(out.decode("utf-8") + "\n")
    
    with open("files/background_files/out_wts_f.txt", "r") as f_wtf:
        l_f_wtf = [line.rstrip('\n') for line in f_wtf]
        tttt= numpy.array(l_f_wtf).astype(numpy.int0)

    with open("files/background_files/out_wts_l.txt", "r") as f_wtl:
        l_f_wtl = [line.rstrip('\n') for line in f_wtl]
        hhhh = numpy.array(l_f_wtl).astype(numpy.int0)

    with open("files/results.txt", "a") as final_f:
        final_f.write("Odchylenie standardowe dla FCFS:\n")
        final_f.write(str(numpy.std(tttt, ddof=0))+"\n")
        final_f.write("Odchylenie standardowe dla LCFS:\n")
        final_f.write(str(numpy.std(hhhh, ddof=0))+"\n")


