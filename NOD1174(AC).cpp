// RMQ problem, using sparse table
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 10000;
int dp[N][15];
int n;
int q;

int main()
{
	int i, j;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &dp[i][0]);
	}
	int b = 2;
	for (j = 1; b <= n; ++j, b <<= 1) {
		for (i = 0; i + b <= n; ++i) {
			dp[i][j] = max(dp[i][j - 1], dp[i + (b >> 1)][j - 1]);
		}
	}
	scanf("%d", &q);
	int x, y;
	for (i = 0; i < q; ++i) {
		scanf("%d%d", &x, &y);
		b = 1;
		j = 0;
		while ((b << 1) <= (y - x + 1)) {
			b <<= 1;
			++j;
		}
		printf("%d\n", max(dp[x][j], dp[y + 1 - b][j]));
	}
	
	return 0;
}