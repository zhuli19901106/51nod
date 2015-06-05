#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 500;
int a[N + 1][N + 1];
int s[N + 1][N + 1];
int n;

int main()
{
	int i, j;
	
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	memset(s, 0, sizeof(s));
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			s[i][j] = max(s[i - 1][j], s[i][j - 1]) + a[i][j];
		}
	}
	printf("%d\n", s[n][n]);
	
	return 0;
}