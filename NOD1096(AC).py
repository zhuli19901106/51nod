import re

def main():
	a = []
	n = int(raw_input())
	for i in xrange(n):
		a.append(int(raw_input()))
	a.sort()
	ans = 0
	for i in xrange(n):
		ans += abs(a[i] - a[(n - 1) / 2])
	print(ans)

if __name__ == '__main__':
	main()