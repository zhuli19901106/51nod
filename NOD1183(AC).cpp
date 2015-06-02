#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
int dp[N][N];
char s1[N], s2[N];
int n1, n2;

int WagnerFischer()
{
	// minimal edit distance
	// Levenshtein
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n1; ++i) {
		dp[i][0] = i;
	}
	for (i = 1; i <= n2; ++i) {
		dp[0][i] = i;
	}
	for (i = 1; i <= n1; ++i) {
		for (j = 1; j <= n2; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	return dp[n1][n2];
}

int main()
{
	gets(s1);
	gets(s2);
	n1 = strlen(s1);
	n2 = strlen(s2);
	printf("%d\n", WagnerFischer());
	
	return 0;
}