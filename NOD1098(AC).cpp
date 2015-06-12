#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 10000;
const LL INF = 1LL << 62;
LL a[N + 1];
LL s[N + 1];
LL s2[N + 1];
int n, m;
LL ans;

int main()
{
	int i;
	
	scanf("%d%d", &m, &n);
	for (i = 1; i <= m; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + m + 1);
	memset(s, 0, sizeof(s));
	memset(s2, 0, sizeof(s2));
	for (i = 1; i <= m; ++i) {
		s[i] = s[i - 1] + a[i];
		s2[i] = s2[i - 1] + a[i] * a[i];
	}
	ans = INF;
	LL sum;
	for (i = n; i <= m; ++i) {
		sum = n * (s2[i] - s2[i - n]) - (s[i] - s[i - n]) * (s[i] - s[i - n]);
		ans = min(ans, sum);
	}
	printf("%lld\n", ans / n);
	
	return 0;
}