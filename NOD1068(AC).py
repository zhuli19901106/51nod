import re

def main():
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		# Why?
		print('A' if n % 3 else 'B')

if __name__ == '__main__':
	main()
