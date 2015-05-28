import re

def gcd(x, y):
	return gcd(y % x, x) if x else y

def main():
	x, y = map(int, re.split('\s+', raw_input().strip()))
	print(gcd(x, y))

if __name__ == '__main__':
	main()
