import csv
import os
import sqlite3

con = sqlite3.connect("./ind/Mary/db.db")
cursor = con.cursor()
cursor.execute("select * from summary;")

res = cursor.fetchall()


