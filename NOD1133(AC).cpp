// O(n ^ 2) is tolerable
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct Term {
	int x, y;
} Term;
Term a[10000];
int dp[10000];
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
	
	for (i = 0; i < n; ++i) {
		dp[i] = 1;
		for (j = 0; j < i; ++j) {
			if (a[j].y <= a[i].x) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a + n, comp);
	printf("%d\n", solve());
	
	return 0;
}