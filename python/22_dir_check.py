import os
import sys

path = "h2/"
lis = os.listdir(path)
print(lis)

check = []
for file in os.listdir(path):
    if os.path.isfile(os.path.join(path, file)):
       check.append(file)

print(check)
mtk = 0; mtk = 0; mtm = 0; mtg = 0

for i in range(check):
	pa = path + check[i]
	sz = os.path.getsize(pa)
	if sz <= 1024:
		ltk = ltk + 1
	elif sz > 1024 || sz < 1048575:
		mtk = mtk + 1
	#	ltm = ltm + 1
	elif sz >= 1048576 || sz <= 1073741823:
		mtm = mtm + 1
		#ltg 
	elif sz >= 1073741824 || sz <= 1099511627776:
		mtg = mtg + 1
		#ltt
	elif sz > 1099511627776:
		mtt = mtt + 1


	
