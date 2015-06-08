#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 1000;
const LL MOD = 1000000007;
LL a[N + 1][N + 1];
int n, m;

int main()
{
	memset(a, 0, sizeof(a));
	int i, j;
	for (i = 1; i <= N; ++i) {
		a[i][1] = a[1][i] = 1;
	}
	for (i = 2; i <= N; ++i) {
		for (j = 2; j <= N; ++j) {
			a[i][j] = (a[i][j - 1] + a[i - 1][j]) % MOD;
		}
	}
	
	scanf("%d%d", &n, &m);
	printf("%lld\n", a[n][m]);
	
	return 0;
}