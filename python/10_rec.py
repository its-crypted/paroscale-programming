import sys
import os
import names

parent = sys.argv[1]
dir_num = int(sys.argv[2])
sub_dirs = sys.argv[3]
f_num = sys.argv[4]
depth = sys.argv[5]

parent = os.path.join(os.getcwd(), parent)
if(os.path.isdir(parent) == True):
	os.chdir(parent)
	print(parent)
else:
	os.mkdir(parent)
	os.chdir(parent)
	print(parent)

i = 0
dn = dir_num
d = int(depth)
def creat_fs():
	for a in range(dn):
		a = names.get_first_name()
		b = names.get_last_name()
		if(os.path.isdir(a) == True):
			os.mkdir(b)
		else:
			os.mkdir(a)

creat_fs()
dir_list = os.listdir(parent)
print(dir_list)

def sub_dir(n):
	for a in range(int(sub_dirs)):
		a = names.get_first_name()
		b = names.get_last_name()
		if(os.path.isdir(a) == True):
			os.mkdir(b)
		else:
			os.mkdir(a)

path = os.path.join(parent, dir_list[i])
for i in range(int(sub_dirs)):
	os.chdir(path)
	sub_dir(int(sub_dirs))
	os.chdir(parent)


