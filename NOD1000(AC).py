import re

def main():
	a, b = map(int, re.split('\s+', raw_input().strip()))
	print(a + b)

if __name__ == '__main__':
	main()
