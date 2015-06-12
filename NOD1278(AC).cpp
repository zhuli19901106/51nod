#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct Term {
	int x, y;
} Term;
const int N = 50000;
Term a[N];
int dp[N];
int n;

bool comp(const Term &t1, const Term &t2)
{
	if (t1.x != t2.x) {
		return t1.x < t2.x;
	} else {
		return t1.y < t2.y;
	}
}

int solve()
{
	int i, j;
	int ll, rr, mm;
	int ans = 0;
	for (i = 0; i < n; ++i) {
		if (a[i].y < a[i + 1].x) {
			ans += n - 1 - i;
			continue;
		}
		if (a[i].y >= a[n - 1].x) {
			continue;
		}
		ll = i + 1;
		rr = n - 1;
		while (rr - ll > 1) {
			mm = (ll + rr) / 2;
			if (a[i].y >= a[mm].x) {
				ll = mm;
			} else {
				rr = mm;
			}
		}
		ans += n - rr;
	}
	
	return ans;
}

int main()
{
	int i;
	int c, r;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &c, &r);
		a[i].x = c - r;
		a[i].y = c + r;
	}
	sort(a, a + n, comp);
	printf("%d\n", solve());
	
	return 0;
}