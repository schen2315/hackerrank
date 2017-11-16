import math
# Enter your code here. Read input from STDIN. Print output to STDOUT
saved = [[0 for i in range(0, 20)] for j in range(0, 20)]
saved[0][0] = 1
saved[1][0] = 1
saved[1][1] = 1
for i in range(0, 20):
	saved[i][0] = 1

def nck(n, k):
    if(n == k):
        return 1
    if(saved[n][k] == 0):
        ans = nck(n-1, k) + nck(n-1, k-1)
        saved[n][k] = ans
        return ans
    else:
        return saved[n][k]
def sol(n, k):
	ans = 0
	sign = 1
	for i in range(0, k+1):
		ans = ans + sign*nck(k, i)*math.factorial(n)
		n = n-1
		sign = -1*sign
	return ans

p = int(input())

for i in range(0, p):
	line = input().split(' ')
	print(i+1, end=' ')
	print(sol(int(line[1]), int(line[2])))
    # print(nck(int(line[0]), int(line[1])))
	