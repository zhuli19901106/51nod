import re

def matmul(a, b):
	MOD = 1000000009
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

def fast_fib(n):
	#[0, 1]
	#[1, 1]
	if n < 2:
		return n
	p = [[0, 1], [1, 1]]
	mp = matpow(p, n - 1)
	return mp[1][1]

def main():
	n = int(raw_input().strip())
	print(fast_fib(n))

if __name__ == '__main__':
	main()