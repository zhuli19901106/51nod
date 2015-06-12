// Minimal positive subarray.
// O(n * log(n)) solution
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long int LL;
const int N = 50000;
typedef struct Term {
	LL sum;
	int idx;
} Term;
LL a[N + 1];
Term s[N + 1];
int n;

bool comp(const Term &t1, const Term &t2)
{
	return t1.sum < t2.sum;
}

int main()
{
	LL ans;
	int i;
	
	scanf("%d", &n);
	s[0].sum = 0;
	s[0].idx = 0;
	for (i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		s[i].sum = s[i - 1].sum + a[i];
		s[i].idx = i;
	}
	sort(s, s + n + 1, comp);
	ans = 1LL << 62;
	for (i = 0; i < n; ++i) {
		if (s[i + 1].sum == s[i].sum || s[i + 1].idx < s[i].idx) {
			continue;
		}
		ans = min(ans, s[i + 1].sum - s[i].sum);
	}
	printf("%lld\n", ans);
	
	return 0;
}