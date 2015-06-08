# Yet another translation in python.
# Perhaps I should be a translator, instead of a lame coder.
import re

N = 400
f = []

def calc():
	global N
	global f
	
	f = [[0, 0] for i in xrange(N)]
	f[1][0] = 1
	f[1][1] = 0
	f[2][0] = 0
	f[2][1] = 1
	for i in xrange(3, N):
		f[i][0] = f[i - 1][0] + f[i - 2][0]
		f[i][1] = f[i - 1][1] + f[i - 2][1]

def bisearch(ll, rr, cc, lv, rv):
	global f
	global n
	
	mm = (ll + rr) / 2
	mv = lv + rv
	if mm <= n + 1:
		if cc == 1:
			ans = lv
		elif lv < mv:
			ans = lv * f[cc + 1][0] + mv * f[cc + 1][1]
		else:
			ans = mv * f[cc + 1][0] + lv * f[cc + 1][1]
		if ll < mm and n >= mm:
			ans = max(ans, bisearch(mm, rr, cc - 1, mv, rv))
	else:
		ans = bisearch(ll, mm, cc - 1, lv, mv)
	return ans

def solve():
	global f
	global n
	
	ll = 1
	cc = 0
	while (ll << 1) <= n:
		ll <<= 1
		cc += 1
	rr = ll << 1
	ans = f[cc + 1][0] + f[cc + 1][1]
	ans = max(ans, bisearch(ll, rr, cc, 1, 1))
	return ans

def main():
	calc()
	
	global n
	
	t = int(raw_input())
	for ti in xrange(t):
		n = int(raw_input())
		print(solve())

if __name__ == '__main__':
	main()
