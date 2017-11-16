n = raw_input()
s = raw_input()

numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"

c = 0
if(set(numbers).isdisjoint(s)):
	#print("num")
	c = c + 1
if(set(lower_case).isdisjoint(s)):
	#print("lower")
	c = c + 1
if(set(upper_case).isdisjoint(s)):
	#print("upper")
	c = c + 1
if(set(special_characters).isdisjoint(s)):
	#print("special")
	c = c + 1
if((len(s) + c) < 6):
	print(c + (6-c-len(s)))
else:
	print(c)