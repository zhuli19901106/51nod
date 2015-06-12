import re

def main():
	d = {}
	for i in xrange(10):
		d[chr(ord('0') + i)] = i
	for i in xrange(26):
		d[chr(ord('A') + i)] = i + 10
	
	n = raw_input().strip()
	m = list(set(list(n)))
	m.sort()
	k = d[m[-1]] + 1
	while k <= 36:
		if int(n, k) % (k - 1) == 0:
			print(k)
			break
		k += 1
	if k > 36:
		print('No Solution')

if __name__ == '__main__':
	main()
