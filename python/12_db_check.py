import sqlite3

connection = sqlite3.connect("./ind/Mary/db.db")
cursor = connection.cursor()
cursor.execute("select * from entries;")

results = cursor.fetchall()

for r in results:
	if
	with open ("check2.csv", "a") as fp:
		fp.write(str(r)+ "\n")

cursor.close()
connection.close()
