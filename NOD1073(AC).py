import re

def main():
	n, k = map(int, re.split('\s+', raw_input().strip()))
	s = 0
	for i in xrange(2, n + 1):
		s = (s + k) % i
	print(s + 1)

if __name__ == '__main__':
	main()
