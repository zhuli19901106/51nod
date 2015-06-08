// Dynamic programming
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000;
char s[N + 1];
int dp[N][N];
int n;

int solve()
{
	int i, j;

	for (i = 0; i < n; ++i) {
		dp[i][i] = 0;
	}
	for (i = 0; i < n - 1; ++i) {
		dp[i][i + 1] = (s[i] != s[i + 1]);
	}
	for (i = 2; i < n; ++i) {
		for (j = 0; j + i < n; ++j) {
			if (s[j] == s[j + i]) {
				dp[j][j + i] = dp[j + 1][j + i - 1];
			} else {
				dp[j][j + i] = 1 + min(dp[j + 1][j + i], dp[j][j + i - 1]);
			}
		}
	}
	return dp[0][n - 1];
}

int main()
{
	gets(s);
	n = strlen(s);
	printf("%d\n", solve());
	
	return 0;
}