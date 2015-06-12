# Count the cyclic lengths of reciprocal fractions
import re

def count_recurring_cycle(n):
	p = [0 for i in xrange(n)]
	i = 1
	r = 1
	while True:
		if r == 0:
			return 0
		if p[r] != 0:
			return i - p[r]
		p[r] = i
		r = r * 10 % n
		i += 1

def main():
	N = 1000
	a = range(N + 1)
	ans = range(N + 1)
	a[0] = 0
	a[1] = 0
	for i in xrange(2, N + 1):
		a[i] = max(a[i - 1], count_recurring_cycle(i))
		if a[i] > a[i - 1]:
			ans[i] = i
		else:
			ans[i] = ans[i - 1]
	
	n = int(raw_input())
	print(ans[n])

if __name__ == '__main__':
	main()
