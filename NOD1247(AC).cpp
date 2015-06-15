#include <cstdio>
using namespace std;

typedef long long int LL;
LL a, b, x, y;

LL gcd(LL x, LL y)
{
	return x ? gcd(y % x, x) : y;
}

int main()
{
	int t, ti;
	LL gab, gxy;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
		gab = gcd(a, b);
		gxy = gcd(x, y);
		printf(gab == gxy ? "Yes\n" : "No\n");
	}
	
	return 0;
}