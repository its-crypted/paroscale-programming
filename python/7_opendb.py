import sqlite3

connection = sqlite3.connect("../assignment/ind/db.db")
cursor = connection.cursor()
cursor.execute("select * from entries;")
print()
results = cursor.fetchall()
for r in results:
	print(r)
cursor.close()
connection.close()
