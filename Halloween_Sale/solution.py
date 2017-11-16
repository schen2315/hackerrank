st = raw_input().split(' ')
p = int(st[0])
d = int(st[1])
m = int(st[2])
s = int(st[3])

n = 0
while(s >= p):
	s = s - p
	n = n + 1
	if(p > m):
		p = p - d
		if(p <= m):
			p = m
	#else:
	#	p = m
print(n)