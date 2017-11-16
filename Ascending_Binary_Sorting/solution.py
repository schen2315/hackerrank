#!/bin/python3

import sys
import os

def count_ones(num):
	cnt = 0
	while(num > 0):
		if(num % 2 == 1):
			cnt = cnt + 1
		num = num // 2
	return cnt
def compare(val1, val2):
	if(val1[1] > val2[1]):
		return 1
	elif(val1[1] < val2[1]):
		return -1
	else:
		if(val1[0] > val2[0]):
			return 1
		elif(val1[0] < val2[0]):
			return -1
		else:
			return 0
print(count_ones(1))
def rearrange(elements):
	num_ones = []
	for i in range(0, len(elements)):
		x = count_ones(elements[i])
		num_ones.append(x)
	pairs = zip(elements, num_ones)
	sorted_pairs = sorted(pairs, cmp=compare)
	unzipped = zip(*sorted_pairs)
	retval = list(unzipped[0])
	return retval
if __name__ == "__main__":
    f = open(os.environ['OUTPUT_PATH'], 'w')

    elements_cnt = 0
    elements_cnt = int(input())
    elements_i = 0
    elements = []
    while elements_i < elements_cnt:
        elements_item = int(input())
        elements.append(elements_item)
        elements_i += 1


    res = rearrange(elements);
    for res_cur in res:
        f.write( str(res_cur) + "\n" )


    f.close()