import math
import re

def solve(n):
	r = int(math.sqrt(2 * (n - 1)))
	return 1 if n == r * (r + 1) / 2 + 1 else 0

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(solve(n))

if __name__ == '__main__':
	main()
