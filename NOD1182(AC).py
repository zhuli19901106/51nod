def main():
	s = [ord(val) - ord('a') for val in list(raw_input().lower())]
	c = [0 for val in xrange(26)]
	for val in s:
		c[val] += 1
	c.sort(reverse = True)
	sum = 0
	for i in xrange(26):
		sum += c[i] * (26 - i)
	print(sum)

if __name__ == '__main__':
	main()
