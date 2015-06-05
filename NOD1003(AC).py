# Trailing zeros of n!
import re

def main():
	n = int(raw_input())
	i = 5
	sum = 0
	while i <= n:
		sum += n / i
		i *= 5
	print(sum)

if __name__ == '__main__':
	main()
