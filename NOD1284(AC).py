def count(p, n):
	pc = len(p)
	m = 1 << pc
	ans = n
	for i in xrange(m):
		f = -1
		sum = 1
		for j in xrange(pc):
			if i & (1 << j) == 0:
				continue
			f = -f
			sum *= p[j]
		ans += f * (n / sum)
	return ans

def main():
	p = [2, 3, 5, 7]
	n = int(raw_input())
	print(n - count(p, n))

if __name__ == '__main__':
	main()
