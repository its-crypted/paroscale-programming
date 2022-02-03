import os
import names

path = str(input("Enter parent dir name to which you want dir structure: "))
parent = os.path.join(os.getcwd(), path)
if(os.path.isdir(parent) == True):
	os.chdir(parent)
else:
	os.mkdir(parent)
	os.chdir(parent)

dir_num = int(input("Enter number of dir you want? "))
f_num = input(int("Enter number of files you want? "))

for a in range(dir_num):
	a = names.get_first_name()
	if(os.path.isdir(a) == True):
		continue
	else:
		os.mkdir(a)


