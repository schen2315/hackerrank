# Enter your code here. Read input from STDIN. Print output to STDOUT
N, Q = map(int, raw_input().strip().split(' '))
arr = map(int, raw_input().strip().split(' '))
for i in xrange(0, Q):
    x, k, t = map(int, raw_input().strip().split(' '))
    ind = 0
    if t == 0:
        while ind < N and arr[ind] < x:
            ind = ind + 1
        if ind >= 0 and ind < N and arr[ind] != x:
            ind = ind - 1
        if ind + k >= N:
            print -1
            continue
        print arr[ind+k]
    else:
        ind = N-1 
        while ind >= 0 and arr[ind] > x:
            ind = ind - 1
        if ind >= 0 and ind < N and arr[ind] != x:
            ind = ind + 1
        if ind - k >= N or ind-k < 0:
            print -1
            continue
        print arr[ind-k]