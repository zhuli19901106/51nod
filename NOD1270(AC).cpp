#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 50000;
int a[N];
int dp[N][2];
int n;

int myabs(int x)
{
	return x > 0 ? x : -x;
}

int solve()
{
	int i;
	
	dp[0][0] = dp[0][1] = 0;
	for (i = 1; i < n; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + myabs(1 - a[i - 1]));
		dp[i][1] = max(dp[i - 1][0] + myabs(a[i] - 1), dp[i - 1][1] + myabs(a[i] - a[i - 1]));
	}
	return max(dp[n - 1][0], dp[n - 1][1]);
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", solve());
	
	return 0;
}