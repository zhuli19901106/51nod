import re

def mypow(a, b, c):
	if b == 0:
		return 1 % c
	if b == 1:
		return a % c
	t = mypow(a, b / 2, c)
	if b & 1:
		return t * t % c * a % c
	else:
		return t * t % c

def main():
	a, b, c = map(int, re.split('\s+', raw_input().strip()))
	print(mypow(a, b, c))

if __name__ == '__main__':
	main()
