# Daffodil number
import bisect
import re

def main():
	a = [153, 370, 371, 407, 1634, 8208, 9474]
	n = int(raw_input())
	i = bisect.bisect_left(a, n)
	print(a[i])

if __name__ == '__main__':
	main()
