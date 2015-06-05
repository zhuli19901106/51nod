import re

def main():
	MOD = 10 ** 9 + 7
	N = 1000
	a = [0 for i in xrange(N + 1)]
	a[0] = a[1] = 1
	for i in xrange(2, N + 1):
		a[i] = (a[i - 1] + a[i - 2]) % MOD
	n = int(raw_input())
	print(a[n])

if __name__ == '__main__':
	main()
