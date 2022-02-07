import os
import random
import names
import sys

parent = sys.argv[1]	#dir name
init_dirs = sys.argv[2]	#initial dir num
sub_dirs = sys.argv[3]	#sub dirs to create
file_no = sys.argv[4]	#no of files to create
depth = sys.argv[5]	#depth

os.mkdir(parent)

path = os.path.join(os.getcwd(), parent)
os.chdir(path)
print(os.getcwd())

def create_dir_struct():
	for i in range(int(sub_dirs)):
		a = names.get_first_name()
		b = names.get_last_name()
		if(os.path.isdir(a) == True):
			os.mkdir(b)
		else:
			os.mkdir(a)

def create_file_struct():
	for i in range(int(file_no)):
		a = names.get_first_name()
		b = names.get_last_name()
		if(os.path.isfile(a) == True):
			with open(b + ".txt", 'w') as fp:
				continue
		else:
			with open(a + ".txt", 'w') as fp:
				continue

for i in range(int(init_dirs)):
	for j in range(int(depth)):
		a = names.get_first_name()
		b = names.get_last_name()
		if(os.path.isdir(a) == True):
			os.mkdir(b)
			os.chdir(b)
		else:
			os.mkdir(a)
			os.chdir(a)
		print(os.getcwd())
		create_dir_struct()
		create_file_struct()
os.getcwd()

