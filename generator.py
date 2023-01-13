import numpy as np

overall_range = 100
processes_normal_left = 299
processes_normal_right = 1
processes_uni_left = 95
processes_uni_right = 1
pages_left = 50
pages_right = 1


norm_nums = [np.random.normal(processes_normal_left, processes_normal_right) for _ in range(overall_range)]
uniform_nums = [np.random.uniform(processes_uni_left, processes_uni_right) for _  in range(overall_range)]
uniform_nums_2 = [np.random.uniform(pages_left, pages_right) for _  in range(overall_range)]


with open('files/background_files/generated_pages.txt', 'w') as fp:
    for id in range(overall_range):
        formatted_number_u2 = "{:.0f}".format(uniform_nums_2[id])
        fp.write(str(formatted_number_u2) + '\n')

with open('files/background_files/generated_processes.txt', 'w') as f:
    for id in range(overall_range):
        formatted_number_u = "{:.0f}".format(uniform_nums[id])
        formatted_numbe_n = "{:.0f}".format(norm_nums[id])
        f.write(str(formatted_number_u) + '\t' + str(formatted_numbe_n) + '\n')
