#include <cstdio>
using namespace std;

typedef long long int LL;

LL gcd(LL x, LL y)
{
	return x ? gcd(y % x, x) : y;
}

int main()
{
	int t, ti;
	LL a, b;
	LL tmp;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld%lld", &a, &b);
		tmp = a + 3 * b;
		b = 4 * (a + b);
		a = tmp;
		tmp = gcd(a, b);
		a /= tmp;
		b /= tmp;
		printf("%lld/%lld\n", a, b);
	}
	
	return 0;
}