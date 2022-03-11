import os
import sqlite3
import sys
import random
import string
import time
import subprocess
from pathlib import Path

parent = sys.argv[1]    #parent dir name
indx = sys.argv[2]          #index name

ech = subprocess.Popen(('echo', 'y'), stdout=subprocess.PIPE)
subprocess.check_output(('bdm-create-outtree-index', parent, indx), stdin=ech.stdout)
path = "ind/.bdm.db"
con = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select atime from entries")
res = cursor.fetchall()
atime = res[0][0]
# check for name to be deleted in entries table
#    conn = sqlite3.connect(path)
#    cur2 = conn.cursor()
#    cur2.execute("select name from entries;")
#    r = cur2.fetchall()
#    name = r[0][0]
#    print(name)
fil = [f for f in os.listdir( parent ) if os.path.isfile(parent + f)]
print(fil)
print(len(fil))
print(fil[0])
t = parent + fil[0]
print(t)
if fil == []:
	exit()
subprocess.run(["cat", parent + 'check_read'])     
print("---------------------< Update Next > -----------------------")
ech = subprocess.Popen(('echo', 'y'), stdout=subprocess.PIPE)
subprocess.check_output(('bdm-update-outtree-index', parent, indx), stdin=ech.stdout)
con = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select atime from entries;")
res1 = cursor.fetchall()
atime1 = res1[0][0]
print()

#    conn = sqlite3.connect(path)
#    cur2 = conn.cursor()
#    cur2.execute("select name from entries;")
#    r = cur2.fetchall()
#    if r == []:
#    	break
#    else:
#    	name2 = r[0][0]
#    assert name != name2
print("----------------The updated value are as follows-------------------")
