# Enter your code here. Read input from STDIN. Print output to STDOUT
saved = [[0 for i in range(0, 200)] for j in range(0, 200)]
saved[0][0] = 1
saved[1][0] = 1
saved[1][1] = 1
for i in range(0, 200):
	saved[i][0] = 1

def nck(n, k):
#    if n == 1 and k == 1:
#        return 1
#    if n == 1 and k == 0:
#        return 1
#    if n == 0 and k == 0:
#        return 0
    if(n == k):
        return 1
    if(saved[n][k] == 0):
        ans = nck(n-1, k) + nck(n-1, k-1)
        saved[n][k] = ans
        return ans
    else:
        return saved[n][k]
n = int(input())
#for i in range(0, 200):
##    print('\n')
#    for j in range(0, 200):
#        print(saved[i][j], sep=' ')
for i in range(0, n):
    line = input().split(' ')
    print(nck(int(line[0]), int(line[1])))