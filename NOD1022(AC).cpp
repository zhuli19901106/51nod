// O(n ^ 2) solution using DP
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 1000;
const LL INF = 1LL << 62;
LL a[2 * N];
LL sum[2 * N];
LL dp[2 * N][2 * N];
int s[2 * N][2 * N];
int n;

LL solve()
{
	int i, j, k;
	int n0 = n;
	
	n = 2 * n - 1;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; ++i) {
		s[i][i] = i;
	}
	for (i = 1; i <= n - 1; ++i) {
		s[i][i + 1] = i;
		dp[i][i + 1] = a[i] + a[i + 1];
	}
	for (i = 2; i < n0; ++i) {
		for (j = 1; j + i <= n; ++j) {
			dp[j][j + i] = INF;
			for (k = s[j][j + i - 1]; k <= s[j + 1][j + i]; ++k) {
				if (dp[j][k] + dp[k + 1][j + i] < dp[j][j + i]) {
					dp[j][j + i] = dp[j][k] + dp[k + 1][j + i];
					s[j][j + i] = k;
				}
			}
			dp[j][j + i] += (sum[j + i] - sum[j - 1]);
		}
	}
	LL ans = INF;
	n = n0;
	for (i = 1; i <= n; ++i) {
		ans = min(ans, dp[i][i + n0 - 1]);
	}
	return ans;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	memset(sum, 0, sizeof(sum));
	for (i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (i = n + 1; i < 2 * n; ++i) {
		a[i] = a[i - n];
		sum[i] = sum[i - 1] + a[i];
	}
	printf("%lld\n", solve());
	
	return 0;
}