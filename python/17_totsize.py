import os
import glob

path = str("./h1/Mary/")
os.chdir(path)
txt = glob.glob("*.txt")
k = 0
for i in range(len(txt)):
	print(txt[i])
	file_sz = os.path.getsize(txt[i])
	print(file_sz)
	k += file_sz
print(k)
