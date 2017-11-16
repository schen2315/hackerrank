# Enter your code here. Read input from STDIN. Print output to STDOUT
import string
n = int(input())
m = ""
strs = ["" for x in range(0, 16)]
for i in range(0,n):
	m = input()
	strs = m
	#print(strs)
	a = [[0 for x in range(0,4)] for y in range(0,4)]
	k = 0
	for i in range(0, 4):
		for j in range(0,4):
			a[i][j] = 0 if strs[k] == '0' else 1
			k = k+1
			#print(a[i][j], end='')
		#print('', end='\n')
	#print('', end='\n')
	rotated = list(zip(*a[::-1]))
#	for i in range(0, 4):
#		for j in range(0,4):
#			print(rotated[i][j], end='')
#		print('', end='\n')
#	print('', end='\n')
	flattened = ["" for x in range(0,16)]
	k = 0
	for i in range(0,4):
		for j in range(0,4):
			flattened[k] = '0' if rotated[i][j] == 0 else '1'
			k = k +1
#	print(''.join(flattened)[0:5], end='\n')
#	print(int(''.join(flattened)[0:5],2))		
#	print(''.join(flattened)[5:10], end='\n')
#	print(int(''.join(flattened)[5:10],2))	
#	print(''.join(flattened)[10:15], end='\n')
#	print(int(''.join(flattened)[10:15],2))	
	#print(list('abcdefghijklmnopqrstuvwxyz'))
	#pair = list(zip(list('abcdefghijklmnopqrstuvwxyz'), range(1, 27)))
	letters = list('abcdefghijklmnopqrstuvwxyz')
	print(''.join([letters[int(''.join(flattened)[0:5],2) -1], letters[int(''.join(flattened)[5:10],2)-1], letters[int(''.join(flattened)[10:15],2) -1]]), end='\n')
	
	
	
	
	