import re

MOD = 7

def matmul(a, b):
	global MOD
	
	c = [[0, 0], [0, 0]]
	c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD
	c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD
	c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD
	c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD
	return c

def matpow(p, n):
	if n == 1:
		return p
	mp = matpow(p, n >> 1)
	ans = matmul(mp, mp)
	if n & 1:
		ans = matmul(ans, p)
	return ans

def fast_fib(n, a, b):
	global MOD
	
	if n < 3:
		return 1
	a %= MOD
	b %= MOD
	p = [[0, 1], [b, a]]
	mp = matpow(p, n - 2)
	return (mp[1][0] + mp[1][1]) % MOD

def main():
	a, b, n = map(int, re.split('\s+', raw_input().strip()))
	print(fast_fib(n, a, b))

if __name__ == '__main__':
	main()