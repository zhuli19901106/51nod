#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200;
const int W = 50000;
int dp[W + 1];
int w[N], p[N];
int n, tw;

int main()
{
	int i, j;
	int sum;
	
	scanf("%d%d", &n, &tw);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &w[i], &p[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	sum = 0;
	for (i = 0; i < n; ++i) {
		sum += w[i];
		for (j = sum; j >= w[i]; --j) {
			if (dp[j - w[i]] == -1) {
				continue;
			}
			dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
		}
	}
	
	sum = 0;
	for (i = 0; i <= tw; ++i) {
		sum = max(sum, dp[i]);
	}
	printf("%d\n", sum);
	
	return 0;
}