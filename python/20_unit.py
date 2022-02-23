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
    path = str(input("Enter the database path to check: "))
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
#    print("The current values of DB are as follows.")
#    print("Total files for db now", totfiles)
#    print("Total size for db now", totsize)
#    print("Total size of files less than or equal to 1kb(size <= 1024) now", totltk)
#    print("Total size size greater than 1kb(size > 1024) now", totmtk)
#    print("Total size less than or equal to 1mb(size <= 1048576) now", totltm)
#    print("Total size greater than 1mb(size > 1048576) now", totmtm)
#    print("Total size greater than 1gb(size > 1073741824) now", totmtg)
#    print("Total size greater than 1tb(size > 1099511627776) now", totmtt)
    print()
    subprocess.run(["gufi_dir2index", parent, indx])
    con = sqlite3.connect(path)
    cursor = con.cursor()
    res = cursor.fetchall()
    totfiles1 = res[0][0]
    totsize1 = res[0][1]
    totltk1 = res[0][2]
    totmtk1 = res[0][3]
    totltm1 = res[0][4]
    totmtm1 = res[0][5]
    totmtg1 = res[0][6]
    totmtt1 = res[0][7]
#    print("Total files for db now", totfiles1)
#    print("Total size for db now", totsize1)
#    print("Total size of files less than or equal to 1kb(size <= 1024) now", totltk1)
#    print("Total size size greater than 1kb(size > 1024) now", totmtk1)
#    print("Total size less than or equal to 1mb(size <= 1048576) now", totltm1)
#    print("Total size greater than 1mb(size > 1048576) now", totmtm1)
#    print("Total size greater than 1gb(size > 1073741824) now", totmtg1)
#    print("Total size greater than 1tb(size > 1099511627776) now", totmtt1)
    print("------------------------------------------------------------------")
    print()
    print("----------------The updated value are as follows-------------------")
    print("Total Files -> Old value: " + str(totfiles) + " New Value: " + str(totfiles1))
    print("Total Size -> Old value: " + str(totsize) + " New Value: " + str(totsize1))
    print("Total lteq kb -> Old value: " + str(totltk) + " New Value: " + str(totltk1))
    print("Total gt kb -> Old value: " + str(totmtk) + " New Value: " + str(totmtk1))
    print("Total lteq mb -> Old value: " + str(totltm) + " New Value: " + str(totltm1))
    print("Total mt mb -> Old value: " + str(totmtm) + " New Value: " + str(totmtm1))
    print("Total mt gb -> Old value: " + str(totmtg) + " New Value: " + str(totmtg1))
    print("Total mt tb -> Old value: " + str(totmtt) + " New Value: " + str(totmtt1))
