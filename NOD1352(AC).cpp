// Integer solution to linear equation
#include <cstdio>
using namespace std;

typedef long long int LL;

LL gcd(LL x, LL y)
{
	return x ? gcd(y % x, x) : y;
}

LL lcm(LL x, LL y)
{
	return x / gcd(x, y) * y;
}

void solve(LL a, LL b, LL c, LL &x, LL &y)
{
	// Recursion, use it wisely
	if (a > b) {
		solve(b, a, c, y, x);
		return;
	}

	if (a == 0) {
		x = 0;
		y = c;
		return;
	}

	LL p, q;

	p = c / a;
	q = b / a;
	LL m, n;
	solve(b % a, a, c % a, m, n);
	y = m;
	x = p - q * y + (c % a - b % a * y) / a;
}

int main()
{
	int t, ti;
	LL n, a, b;
	LL g;
	LL ans;
	LL x, y;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld%lld%lld", &n, &a, &b);
		++n;
		g = gcd(a, b);
		if (n % g) {
			printf("0\n");
			continue;
		}
		a /= g;
		b /= g;
		n /= g;
		solve(a, b, n, x, y);
		//printf("%lld * %lld + %lld * %lld = %lld\n", a, x, b, y, n);
		x = x > 0 ? x % b : (b - (b - x) % b) % b;
		y = (n - a * x) / b;
		if (y <= 0) {
			printf("0\n");
			continue;
		}
		ans = (n / a - x) / b + 1;
		if (n % a == 0) {
			--ans;
		}
		if (n % b == 0) {
			--ans;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}