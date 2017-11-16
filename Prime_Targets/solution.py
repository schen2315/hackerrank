# Enter your code here. Read input from STDIN. Print output to STDOUT
def rwh_primes(n):
    # https://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)/(2*i)+1)
    return [2] + [i for i in xrange(3,n,2) if sieve[i]]
primes = rwh_primes(100000)
pn = len(primes)
x = int(raw_input())
a = map(int, raw_input().strip().split(' '))
ans = 0
while x > 1:
    j = 0
    while (x - primes[j] > 0):
        ans = ans + (a[x-1] - a[x-1-primes[j]])
        j = j+1
    x = x - 1
print ans
