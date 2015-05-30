#include <cstdio>
using namespace std;

typedef long long int LL;

LL gcd(LL x, LL y, LL &a, LL &b)
{
	if (x == 0) {
		a = 0;
		b = 1;
		return y;
	}
	gcd(y % x, x, a, b);
	LL tmp = a;
	a = b - y / x * a;
	b = tmp;
}

LL modinv(LL x, LL y)
{
	LL a, b;
	
	gcd(x, y, a, b);
	a = a >= 0 ? a: y - (y - a) % y;
	return a % y;
}

int main()
{
	const int N = 10;
	LL p[N], r[N], m[N], t[N];
	int i;
	int n;
	LL sum;
	
	scanf("%d", &n);
	sum = 1;
	for (i = 0; i < n; ++i) {
		scanf("%lld%lld", &p[i], &r[i]);
		sum *= p[i];
	}
	
	LL ans = 0;
	for (i = 0; i < n; ++i) {
		// Don't "% p[i]"
		m[i] = sum / p[i];
		t[i] = modinv(m[i], p[i]);
		ans += r[i] * t[i] * m[i];
	}
	ans %= sum;
	printf("%lld\n", ans);
	
	return 0;
}