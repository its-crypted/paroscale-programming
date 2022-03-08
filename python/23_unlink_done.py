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
                fp.truncate(random.randint(0,10737418242))
                fp.close()
                allfiles.append(p)
            mdepth = os.path.relpath(root, str(parent)).count(os.sep)
    alldirs = list(set(alldirs))
    allfiles = list(set(allfiles))
    return alldirs, allfiles

create_random_tree(parent, file, dir, depth)

while True:
#    subprocess.run(["echo y"], stdin=subprocess.PIPE, ["bdm-create-outtree-index", parent, indx])
   # subprocess.getoutput('echo y | bdm-create-outtree-index parent indx')
#    os.system("echo y | bdm-create-outtree-index", parent, indx)
#    subprocess.call(['echo y', subprocess.PIPE, 'bdm-create-outtree-index', parent, indx])
    ech = subprocess.Popen(('echo', 'y'), stdout=subprocess.PIPE)
    subprocess.check_output(('bdm-create-outtree-index', parent, indx), stdin=ech.stdout)
    path = "ind/.bdm.db"
    con = sqlite3.connect(path)
    cursor = con.cursor()
    cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from summary;")
    res = cursor.fetchall()

    # check for name to be deleted in entries table
#    conn = sqlite3.connect(path)
#    cur2 = conn.cursor()
#    cur2.execute("select name from entries;")
#    r = cur2.fetchall()
#    name = r[0][0]
#    print(name)

    #check for the file size
#    lis = os.listdir(parent)
#    check = []
#    for file in os.listdir(parent):
#        if os.path.isfile(os.path.join(parent, file)):
#           check.append(file)
#    
#    ltk = 0; mtk = 0; ltm = 0; mtm = 0; mtg = 0; mtt = 0
#    kb = 1024; mb = 1048576; gb = 1073741824; tb = 1099511627776
#    
#    for i in range(len(check)):
#    	pa = parent + check[i]
#    	sz = os.path.getsize(pa)
#    	if sz <= kb:
#    		ltk = ltk + 1
#    		break
#    	elif sz > kb and sz < mb and sz < gb and sz < tb:
#    		mtk = mtk + 1
#    		ltm = ltm + 1
#    		break
#    	elif sz > kb and sz > mb and sz < gb and sz < tb:
#    		mtm = mtm + 1
#    		mtk = mtk + 1
#    	elif sz > mb and sz > gb and sz < tb:
#    		mtm = mtm + 1
#    		mtk = mtk + 1
#    		mtg = mtg + 1
#    	if sz > tb:
#    		mtm = mtm + 1
#    		mtk = mtk + 1
#    		mtg = mtg + 1
#    		mtt = mtt + 1
#    print("ltk", ltk)
#    print("mtk", mtk)
#    print("ltm", ltm)
#    print("mtm", mtm)
#    print("mtg", mtg)
#    print("mtt", mtt)
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
    f_size = os.path.getsize(dirpath + fil[0])
    print(os.listdir(dirpath))
    if fil[0] == []:
    	break
    else:
        subprocess.run(["rm", dirpath + fil[0]])

    print("---------------------< Update Next > -----------------------")
    ech = subprocess.Popen(('echo', 'y'), stdout=subprocess.PIPE)
    subprocess.check_output(('bdm-update-outtree-index', parent, indx), stdin=ech.stdout)
    con = sqlite3.connect(path)
    cursor = con.cursor()
    cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from summary; ")
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
    assert totfiles1 == totfiles - 1	     
    assert totsize1  == totsize - f_size
    if totltk == totltk1 or totltk == totltk1-1:
    	pass
    if totmtk == totmtk1 or totmtk == totmtk1-1:
    	pass
    if totltm == totltm1 or totltm == totltm1-1:
    	pass
    if totmtm == totmtm1 or totltk == totmtm1-1:
    	pass
    if totmtg == totmtg1 or totmtg == totmtg1-1:
    	pass
    if totmtt == totmtt1 or totmtt == totmtt1-1:
    	pass

#    print("Old value: ", totltk, "New vlaue: ", totltk1) 
#    print("Old value: ", totmtk, "New value: ", totmtk1)      
#    print("Old value: ", totltm, "New value: ", totltm1)	       
#    print("Old value: ", totmtm, "New value: ", totmtm1)	       
#    print("Old value: ", totmtg, "New value: ", totmtg1)	       
#    print("Old value: ", totmtt, "New value: ", totmtt1)

