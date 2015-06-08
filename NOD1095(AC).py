import re

def main():
	n = int(raw_input())
	dw = set()
	da = dict()
	for i in xrange(n):
		s = raw_input().strip()
		dw.add(s)
		s = ''.join(sorted(list(s)))
		if s in da:
			da[s] += 1
		else:
			da[s] = 1
	n = int(raw_input())
	for i in xrange(n):
		s = raw_input()
		s1 = ''.join(sorted(list(s)))
		if s1 in da:
			print(da[s1] - 1 if s in dw else da[s1])
		else:
			print(0)

if __name__ == '__main__':
	main()
