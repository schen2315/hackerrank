import sys

n = int(raw_input())
for i in range(0, n):
	t = int(raw_input().split(' ')[1])
	arr = raw_input().split(' ')
	arr = map(int, arr)
	while(len(arr) != t):
		arr = arr + map(int, raw_input().split(' '))
	sorted_arr = sorted(arr)
	j = 0
	ans = 0
	for k in range(0, len(arr)):
		if(sorted_arr[j] == arr[k]):
			j = j + 1
			ans = ans + 1
	#print i+1,
	#print (len(arr) - ans)
	sys.stdout.write(str(i+1))
	sys.stdout.write(' ')
	sys.stdout.write(str(len(arr)-ans))
	sys.stdout.write('\n')
	