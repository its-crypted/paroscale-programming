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
ltk = 0; mtk = 0; mtm = 0; mtg = 0; mtt = 0

for i in range(len(check)):
	pa = path + check[i]
	sz = os.path.getsize(pa)
	if sz <= 1024:
		ltk = ltk + 1
	elif sz > 1024 or sz < 1048576:
		mtk = mtk + 1
	#	ltm = ltm + 1
	elif sz >= 1048576 or sz < 1073741824:
		mtm = mtm + 1
		#ltg 
	elif sz >= 1073741824 or sz <= 1099511627776:
		mtg = mtg + 1
		#ltt
	elif sz > 1099511627776:
		mtt = mtt + 1

print(ltk)
print(mtk)
print(mtm)
print(mtg)
print(mtt)

	
