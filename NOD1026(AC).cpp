#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const LL N = 1000000;
LL b[N + 1];
LL r[N + 1];
LL c[N + 1];
LL aa, bb, mm, nn;

void sieve()
{
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	LL i, j;
	LL e;

	for (i = 0; i <= N; ++i) {
		r[i] = i;
		c[i] = 1;
	}
	for (i = 2; i <= N / i; ++i) {
		if (r[i] < i) {
			continue;
		}
		e = i;
		j = 1;
		while (e <= N / i) {
			e *= i;
			++j;
			r[e] = i;
			c[e] = j;
		}
	}

	memset(b, 0, sizeof(b));
	for (i = aa; i <= aa + nn - 1; ++i) {
		if (b[i]) {
			continue;
		}
		e = i;
		while (e <= (aa + nn - 1) / r[i]) {
			e *= r[i];
			b[e] = 1;
		}
	}
}

LL gcd(LL x, LL y)
{
	if (x == y) {
		return x;
	}

	if (x > y) {
		return gcd(y, x);
	}

	LL t;

	while (x != 0) {
		t = x;
		x = y % x;
		y = t;
	}
	return y;
}

LL lcm(LL x, LL y)
{
	return x / gcd(x, y) * y;
}

LL solve()
{
	LL i, j, k;
	LL f;
	LL e;
	LL ec;
	LL n;
	LL ans;
	LL kk[100];
	LL al;
	LL ll, rr;
	
	ans = 0;
	for (i = aa; i <= aa + nn - 1; ++i) {
		if (b[i]) {
			continue;
		}
		e = i;
		ec = 0;
		while (e <= aa + nn - 1) {
			kk[ec++] = c[e];
			e *= r[i];
		}
		n = 1LL << ec;
		for (j = 1; j < n; ++j) {
			f = -1;
			al = 1;
			ll = INT_MIN;
			rr = INT_MAX;
			for (k = 0; k < ec; ++k) {
				if ((j & (1LL << k)) == 0) {
					continue;
				}
				f = -f;
				al = lcm(al, kk[k]);
				ll = max(ll, bb * kk[k]);
				rr = min(rr, (bb + mm - 1) * kk[k]);
			}
			if (ll == INT_MIN) {
				printf("F**k you!\n");
			}
			if (ll > rr) {
				continue;
			}
			ans += f * (rr / al - (ll - 1) / al);
		}
	}
	
	return ans;
}

int main()
{
	scanf("%lld%lld%lld%lld", &mm, &nn, &aa, &bb);
	sieve();
	printf("%lld\n", solve());
	
	return 0;
}