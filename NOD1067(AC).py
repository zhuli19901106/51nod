import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print('B' if n % 7 == 0 or n % 7 == 2 else 'A')

if __name__ == '__main__':
	main()
