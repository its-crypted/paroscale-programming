import os
import names
import random

path = str(input("Enter parent dir name to which you want dir structure: "))
parent = os.path.join(os.getcwd(), path)
if(os.path.isdir(parent) == True):
	os.chdir(parent)
else:
	os.mkdir(parent)
	os.chdir(parent)

dir_num = int(input("Enter number of dir you want? "))
#f_num = int(input("Enter number of files you want? "))

dir_list = list()
def create_dir_struct():
	for a in range(dir_num):
		a = names.get_first_name()
		b = names.get_last_name()
		if(os.path.isdir(a) == True):
			os.mkdir(b)
		else:
			os.mkdir(a)

create_dir_struct()
dir_list = os.listdir(parent)
print(dir_list)
print(len(dir_list))
i = 0;
def rand_dirs():
	c = random.randint(0, dir_num)
	os.


def rec_func():
	for i in range(dir_num):
		r = random.randint(0, len(dir_list))
		pa = os.path.join(parent, dir_list[r])
		os.chdir(pa)
		print(os.getcwd())
		create_dir_struct()
		os.chdir(parent)
		
rec_func()

#i = 0
#j = ""
#
#for i in range(len(dir_list)):
#	j = dir_list[i]
#	pa = os.path.join(parent, j)
#	os.chdir(pa)
#	create_dir_struct()
