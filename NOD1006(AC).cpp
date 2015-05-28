#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
char a[N];
char b[N];
char ans[N];
int ac;
int max_len;
int dp[N][N];

void LCS()
{
	int la = strlen(a);
	int lb = strlen(b);
	
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < la; ++i) {
		for (j = 0; j < lb; ++j) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	max_len = dp[la][lb];
	
	int c = max_len;
	int cla = la;
	int clb = lb;
	bool suc;
	ac = 0;
	while (c > 0) {
		suc = false;
		for (i = c - 1; !suc && i < cla; ++i) {
			for (j = c - 1; !suc && j < clb; ++j) {
				if (dp[i + 1][j + 1] == c && a[i] == b[j]) {
					suc = true;
					cla = i;
					clb = j;
					ans[ac++] = a[i];
					--c;
				}
			}
		}
	}
	ans[ac] = 0;
	reverse(ans, ans + ac);
}

int main()
{
	gets(a);
	gets(b);
	LCS();
	puts(ans);

	return 0;
}