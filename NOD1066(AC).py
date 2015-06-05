import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n, k = map(int, re.split('\s+', raw_input()))
		print('A' if n % (k + 1) else 'B')

if __name__ == '__main__':
	main()
