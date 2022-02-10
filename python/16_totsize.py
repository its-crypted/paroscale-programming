import glob
import sqlite3

path = str(input("Enter the path to database you want to check: "))

print("Enter for which operation you want to check")
print("1. Check for total files")
print("2. Check for total size of files")
print("3. Check for total
switch c:
	case 1:


con = sqlite3.connect(path)
cursor = con.cursor()
cursor.execute("select totsize from summary")
res = cursor.fetchall()
os.chdir("./h1/Mary")

