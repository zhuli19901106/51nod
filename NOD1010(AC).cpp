#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long int LL;
const LL N = 1000000000000000000;
LL a[11000];
int ac;

int main()
{
	int i;
	
	ac = 0;
	a[ac++] = 1;
	
	int d[3] = {2, 3, 5};
	int p[3];
	LL s[3];
	LL mx;
	
	p[0] = p[1] = p[2] = 0;
	while (a[ac - 1] <= N) {
		for (i = 0; i < 3; ++i) {
			s[i] = a[p[i]] * d[i];
		}
		mx = min(s[0], min(s[1], s[2]));
		a[ac++] = mx;
		for (i = 0; i < 3; ++i) {
			if (s[i] == mx) {
				++p[i];
			}
		}
	}
	
	int t, ti;
	LL n;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld", &n);
		i = lower_bound(a + 1, a + ac, n) - a;
		printf("%lld\n", a[i]);
	}

	return 0;
}