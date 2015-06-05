import re

def gcd(x, y):
	return gcd(y % x, x) if x else y

def lcm(x, y):
	return x / gcd(x, y) * y

def main():
	x, y = map(int, re.split('\s+', raw_input()))
	print(lcm(x, y))

if __name__ == '__main__':
	main()
