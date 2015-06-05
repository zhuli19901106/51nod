import math

def main():
	n = int(raw_input())
	cc = 0
	i = 0
	while 2 * i * i <= n:
		j = int(math.sqrt(n - i * i))
		if i * i + j * j == n:
			print('%d %d' % (i, j))
			cc += 1
		i += 1
	if cc == 0:
		print('No Solution')

if __name__ == '__main__':
	main()
