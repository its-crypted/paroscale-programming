import sqlite3
import os
import sys
import csv

param = sys.argv[1]
path = str(input("Enter the database path to check: "))
check_f = str(input("Enter the Check file name: "))
con = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm, totmtg, totmtt from summary")
# cursor.execute("select totsize from summary")
res = cursor.fetchall()

rows = [['totflies', res[0][0]],
        ['totsize', res[0][1]],
        ["totltk ", res[0][2]],
        ["totmtk ", res[0][3]],
        ["totltm ", res[0][4]],
        ["totmtm ", res[0][5]],
        ["totmtg ", res[0][6]],
        ["totmtt ", res[0][7]]]

with open(check_f, "w") as fp:
    writ = csv.writer(fp)
    writ.writerow(rows)