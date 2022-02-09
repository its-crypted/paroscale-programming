import os
import glob
import sqlite3

con = sqlite3.connect("./ind/Mary/db.db")
cursor = con.cursor()
cursor.execute("select totfiles from summary")
res = cursor.fetchall()
os.chdir("./h1/Mary/")
txt = glob.glob("*.txt")
print(len(txt))
print(res[0][0])

if len(txt) == res[0][0]:
	print("The check is correct")
else:
	print("Check is incorrect")
