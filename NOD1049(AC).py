import re

def max_subarray(a):
	msum = sum = 0
	n = len(a)
	for i in xrange(n):
		sum += a[i]
		msum = max(msum, sum)
		sum = max(sum, 0)
	return msum

def main():
	n = int(raw_input())
	a = []
	for i in xrange(n):
		a.append(int(raw_input()))
	print(max_subarray(a))

if __name__ == '__main__':
	main()
