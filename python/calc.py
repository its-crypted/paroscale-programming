try:
	x = int(input("x: "))
except:
	print("The value entered is not int")
	exit()

try:
	y = int(input("y: "))
except:
	print("The value entered is not int")
	exit()

print(x + y)
