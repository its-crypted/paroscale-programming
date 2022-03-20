import os
import sqlite3
import sys
import subprocess
from pathlib import Path
import gen_tree

parent = sys.argv[1]
indx = sys.argv[2]

if __name__ == '__main__':
	gen_tree.create_random_tree(parent, 3, 4,4)

class db:
	def __init__(self, table):
		con = sqlite3.connect(path)
		cursor = con.cursor()
		cursor.execute("select totfiles, totsize, totltk, totmtk, totltm, totmtm,totmtg, totmtt from {}", format(table))
		self.totfiles	=	res[0][0]
		self.totsize	=	res[0][0]
		self.totltk	=	res[0][0]
		self.totmtk	=	res[0][0]
		self.totltm	=	res[0][0]
		self.totmtm	=	res[0][0]
		self.totmtg	=	res[0][0]
		self.totmtt	=	res[0][0]

tree = db('treesummary')
print(tree.totfiles)

if check 
