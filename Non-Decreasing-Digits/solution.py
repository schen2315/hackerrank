saved = [[0 for i in range(0, 80)] for j in range(0, 80)]
saved[0][0] = 1
saved[1][0] = 1
saved[1][1] = 1
for i in range(0, 80):
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
p = int(raw_input())
for i in range(0, p):
	line = raw_input().split(' ')
	k = int(line[1])
	print i+1, 
	print nck(10 + k - 1, k)