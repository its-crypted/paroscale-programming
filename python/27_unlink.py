import os
import sqlite3
import sys
import random
import string
import time
import subprocess
from pathlib import Path
import gen_tree

parent = sys.argv[1]    #parent dir name
indx = sys.argv[2]          #index name

if __name__ == '__main__':
	gen_tree.create_random_tree(parent, 3, 4, 4)

#test.py.creat_random_tree(parent, 3, 4, 4)
#suprocess.Popen(('python test.py'), parent)
#while True:
#    subprocess.run(["echo y"], stdin=subprocess.PIPE, ["bdm_create_outtree_index", parent, indx])
   # subprocess.getoutput('echo y | bdm_create_outtree_index parent indx')
#    os.system("echo y | bdm_create_outtree_index", parent, indx)
#    subprocess.call(['echo y', subprocess.PIPE, 'bdm_create_outtree_index', parent, indx])
ech = subprocess.Popen(('echo', 'y'), stdout=subprocess.PIPE)
subprocess.check_output(('bdm-create-outtree-index', parent, indx), stdin=ech.stdout)
path = "ind/.bdm.db"

con = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from summary;")
res = cursor.fetchall()

totfiles = res[0][0]
totsize = res[0][1]
totltk = res[0][2]
totmtk = res[0][3]
totltm = res[0][4]
totmtm = res[0][5]
totmtg = res[0][6]
totmtt = res[0][7]

conn = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from treesummary;")
re = cursor.fetchall()
tree_totfiles = re[0][0]
tree_totsize = re[0][1]
tree_totltk = re[0][2]
tree_totmtk = re[0][3]
tree_totltm = re[0][4]
tree_totmtm = re[0][5]
tree_totmtg = re[0][6]
tree_totmtt = re[0][7]


print("The current values of DB are as follows.")
print("Total files: ", totfiles)
print("Total size: ", totsize)
print("Total size of files less than or equal to 1kb(size <= 1024): ", totltk)
print("Total size size greater than 1kb(size > 1024): ", totmtk)
print("Total size less than or equal to 1mb(size <= 1048576): ", totltm)
print("Total size greater than 1mb(size > 1048576): ", totmtm)
print("Total size greater than 1gb(size > 1073741824): ", totmtg)
print("Total size greater than 1tb(size > 1099511627776): ", totmtt)
print()
#dirpath = "./h1/"
fil = [ f for f in os.listdir( parent ) if os.path.isfile(parent + f) ] 
print(fil)
if fil == []:
	exit()
f_size = os.path.getsize(parent + fil[0])
print(os.listdir(parent))
subprocess.run(["unlink", parent + fil[0]])

print("_____________________< Update Next > _______________________")
ech = subprocess.Popen(('echo', 'y'), stdout=subprocess.PIPE)
subprocess.check_output(('bdm-update-outtree-index', parent, indx), stdin=ech.stdout)
con = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from summary; ")
res1 = cursor.fetchall()
totfiles1 = res1[0][0]
totsize1 = res1[0][1]
totltk1 = res1[0][2]
totmtk1 = res1[0][3]
totltm1 = res1[0][4]
totmtm1 = res1[0][5]
totmtg1 = res1[0][6]
totmtt1 = res1[0][7]
print()

con = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from treesummary; ")
re1 = cursor.fetchall()
tree_totfiles1 = re1[0][0]
tree_totsize1 = re1[0][1]
tree_totltk1 = re1[0][2]
tree_totmtk1 = re1[0][3]
tree_totltm1 = re1[0][4]
tree_totmtm1 = re1[0][5]
tree_totmtg1 = re1[0][6]
tree_totmtt1 = re1[0][7]
#    conn = sqlite3.connect(path)
#    cur2 = conn.cursor()
#    cur2.execute("select name from entries;")
#    r = cur2.fetchall()
#    if r == []:
#    	break
#    else:
#    	name2 = r[0][0]
#    assert name != name2
print("________________The updated value are as follows___________________")
assert totfiles1 == totfiles - 1	     
assert totsize1  == totsize - f_size
if totltk == totltk1 or totltk == totltk1-1:
	pass
else:
	exit()
if totmtk == totmtk1 or totmtk == totmtk1-1:
	pass
else:
	exit()
if totltm == totltm1 or totltm == totltm1-1:
	pass
else:
	exit()
if totmtm == totmtm1 or totltk == totmtm1-1:
	pass
else:
	exit()
if totmtg == totmtg1 or totmtg == totmtg1-1:
	pass
else:
	exit()
if totmtt == totmtt1 or totmtt == totmtt1-1:
	pass
else:
	exit()

assert tree_totfiles1 == tree_totfiles1 - 1	     
assert tree_totsize1  == tree_totsize1 - f_size
if tree_totltk == tree_totltk1 or tree_totltk == tree_totltk1-1:
	pass
else:
	exit()
if tree_totmtk == tree_totmtk1 or tree_totmtk == tree_totmtk1-1:
	pass
else:
	exit()
if tree_totltm == tree_totltm1 or tree_totltm == tree_totltm1-1:
	pass
else:
	exit()
if tree_totmtm == tree_totmtm1 or tree_totltk == tree_totmtm1-1:
	pass
else:
	exit()
if tree_totmtg == tree_totmtg1 or tree_totmtg == tree_totmtg1-1:
	pass
else:
	exit()
if tree_totmtt == tree_totmtt1 or tree_totmtt == tree_totmtt1-1:
	pass
else:
	exit()

print("------------- Test Success -----------")
#    print("Old value: ", totltk, "New vlaue: ", totltk1) 
#    print("Old value: ", totmtk, "New value: ", totmtk1)      
#    print("Old value: ", totltm, "New value: ", totltm1)	       
#    print("Old value: ", totmtm, "New value: ", totmtm1)	       
#    print("Old value: ", totmtg, "New value: ", totmtg1)	       
#    print("Old value: ", totmtt, "New value: ", totmtt1)

