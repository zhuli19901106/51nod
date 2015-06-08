import re

def cmp(x, y):
	if x[0] != y[0]:
		return x[0] < y[0]
	else:
		return x[1] < y[1]

def solve(a, k):
	s = {}
	n = len(a)
	sum = 0
	for i in xrange(n):
		sum += a[i]
		s[sum] = i
		if sum == k:
			return [1, i + 1]
	res = []
	sum = 0
	for i in xrange(n):
		sum += a[i]
		if (sum - k) in s and s[sum - k] < i:
			res.append([s[sum - k] + 2, i + 1])
		if (sum + k) in s and s[sum + k] > i:
			res.append([i + 2, s[sum + k] + 1])
	if len(res) == 0:
		return -1
	res = sorted(res, cmp = cmp)
	return res[0]

def main():
	n, k = map(int, re.split('\s+', raw_input()))
	a = []
	for i in xrange(n):
		a.append(int(raw_input()))
	ans = solve(a, k)
	if ans == -1:
		print('No Solution')
	else:
		print('%d %d' % (ans[0], ans[1]))

if __name__ == '__main__':
	main()
