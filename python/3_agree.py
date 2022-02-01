s = input("Do you agree? ")

if s == "y" or s == "Y":
	print("Agreed")
elif s == "n" or s == "N":
	print("Not Agreed")

# or we can use a list as below

if s.lower() in ["y", "yes"]:
	print("Agreed")
elif s.lower() in ["n", "no"]:
	print("Not agreed")

