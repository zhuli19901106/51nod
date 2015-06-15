// From Facebook Hacker Cup
#include <climits>
#include <cstdio>
using namespace std;

typedef long long int LL;

LL solve(LL n, LL k, LL c)
{
	LL ans;
	if (k / n * n >= c) {
		ans = c;
	} else {
		ans = k / n * n + c % n + n - k % n;
	}
	return ans;
}

int main()
{
	LL n, k, c;
	LL p;
	LL ans;

	scanf("%lld%lld%lld", &n, &k, &c);
	if (c <= k / n * n) {
		p = n;
		ans = c;
	} else {
		p = k / (c / n + 1);
		ans = n - p + solve(p, k, c);
	}
	printf("%lld\n", ans);
	
	return 0;
}