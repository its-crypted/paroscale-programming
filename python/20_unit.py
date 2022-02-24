import os
import sqlite3
import sys
import random
import string
import time
import subprocess
from pathlib import Path

parent = sys.argv[1]    #parent dir name
file = int(sys.argv[2])     #no of files
dir = int(sys.argv[3])       #no of dirs
depth = int(sys.argv[4])     #depth
indx = sys.argv[5]          #index name

def random_string(min_length=5, max_length=10):
    length = random.randint(min_length, max_length)
    for i in range(10):
        return ''.join(
            random.choice(string.ascii_uppercase + string.digits)
            for _ in range(length)
        )

def create_random_tree(parent, file=4, dir=2,
                       depth=5):
    os.mkdir(parent)
    alldirs = []
    allfiles = []
    for i in range(int(depth)):
        for root, dirs, files in os.walk(str(parent)):
            for _ in range(int(dir)):
                p = Path(root) / random_string()
                p.mkdir(exist_ok=True)
                alldirs.append(p)
            for _ in range(int(file)):
                p = Path(root) / random_string()
                p.touch(exist_ok=True)
                fp = open(p, 'w')
                fp.truncate(random.randint(0,1073741824))
                fp.close()
                allfiles.append(p)
            mdepth = os.path.relpath(root, str(parent)).count(os.sep)
    alldirs = list(set(alldirs))
    allfiles = list(set(allfiles))
    return alldirs, allfiles

create_random_tree(parent, file, dir, depth)

while True:
    subprocess.run(["gufi_dir2index", parent, indx])
    path = "ind/db.db"
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
    dirpath = "./h1/"
    fil = [ f for f in os.listdir( dirpath ) if os.path.isfile(dirpath + f) ] 
    print(fil)
    f_size = os.path.getsize(dirpath + fil)
    print(os.listdir(dirpath))
    if fil[0] = False:
    	break
    else:
        subprocess.run(["rm", dirpath + fil[0]])
    print("*********************< Update > ***********************>")
    subprocess.run(["gufi_dir2index", parent, indx])
    con = sqlite3.connect(path)
    cursor = con.cursor()
    cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from summary;")
    re = cursor.fetchall()
    totfiles1 = re[0][0]
    totsize1 = re[0][1]
    totltk1 = re[0][2]
    totmtk1 = re[0][3]
    totltm1 = re[0][4]
    totmtm1 = re[0][5]
    totmtg1 = re[0][6]
    totmtt1 = re[0][7]
    print()
    print("----------------The updated value are as follows-------------------")
    assert totfiles1 == totfiles - 1	     
    assert totsize1  == totsize - f_size
    if  assert totltk1   == totltk	       
    assert totmtk1   == totmtk	       
    assert totltm1   == totltm	       
    assert totmtm1   == totmtm	       
    assert totmtg1   == totmtg	       
    assert totmtt1   == totmtt	       
