import csv
import os
import sqlite3
import glob

con = sqlite3.connect("./ind/Mary/db.db")
cursor = con.cursor()

#p = os.listdir("./h1/Mary/*.txt")
os.chdir("./h1/Mary/")
all_files = glob.glob("*")
print("all files without hidden: ", all_files)
print(len(all_files))
txt = glob.glob("*.txt")
print(len(txt))
update_nlink = "UPDATE summary SET nlink = ? where id = ?"
data = (len(all_files), 1)
cursor.execute(update_nlink, data)
con.commit()
