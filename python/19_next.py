import glob
import sqlite3
import sys
import os
import csv


param = sys.argv[1]
path = str(input("Enter the database path to check: "))
con = sqlite3.connect(path)
cursor = con.cursor()
res = cursor.fetchall()
os.chdir(param)

print("------------------------OPERATIONS------------------------")
print("1.Check for total files")
print("2.Check for total size of files")
print("3.Check for total size of files less than or equal to 1kb(size <= 1024)")
print("4.Check for file size greater than 1kb(size > 1024)");
print("5.Check for file size less than or equal to 1mb(size <= 1048576)");
print("6.Check for file size greater than 1mb(size > 1048576)");
print("7.Check for file size greater than 1gb(size > 1073741824)");
print("8.Check for file size greater than 1tb(size > 1099511627776)");
print("10.Check for all file attributes");
check = int(input("Enter any one of above: "))

def totfiles():
	cursor.execute("select totfiles from summary")
	res = cursor.fetchall()
	txt = glob.glob("*.txt")
	if len(txt) == res[0][0]:
		print("The check is correct")
	else:
		print("Check is incorrect")

def totsize():
	cursor.execute("select totsize from summary")
	res = cursor.fetchall()
	txt = glob.glob("*.txt")
	k = 0
	for i in range(len(txt)):
		file_sz = os.path.getsize(txt[i])
		k += file_sz
	print(k)

def totltk():
	cursor.execute("select totltk from summary")

def totmtk():
	cursor.execute("select totmtk from summary")

def totltm():
	cursor.execute("select totmtk from summary")
def totmtm():
	cursor.execute("select totmtk from summary")
def totmtg():
	cursor.execute("select totmtk from summary")
def totmtt():
	cursor.execute("select totmtk from summary")

if check == 1:
	totfiles()
elif check == 2:
	totsize()

