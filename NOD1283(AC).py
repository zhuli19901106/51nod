def solve(n):
	ans = 2 * n + 2
	i = 2
	while i <= n / i:
		if n % i != 0:
			i += 1
			continue
		ans = 2 * (i + n / i)
		i += 1
	return ans

def main():
	n = int(raw_input())
	print(solve(n))

if __name__ == '__main__':
	main()
