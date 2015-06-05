import re

def main():
	n = int(raw_input())
	a = []
	ans = n
	for i in xrange(n):
		x, y = map(int, re.split('\s+', raw_input()))
		if y == 1:
			a.append(x)
			continue
		while len(a) > 0:
			if a[-1] < x:
				a.pop()
				ans -= 1
			else:
				ans -= 1
				break
	print(ans)

if __name__ == '__main__':
	main()
