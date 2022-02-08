import csv

with open('check2.csv', mode='r') as fp:
	csvfile = csv.reader(fp)

	for lines in csvfile:
		print(lines)
