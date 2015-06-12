// Remember to memset...
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const LL MOD = 1000000007;
const int N = 1000;
LL a1[2][9 * N + 1];
LL a2[2][9 * N + 1];

LL solve(int n)
{
	memset(a1, 0, sizeof(a1));
	memset(a2, 0, sizeof(a2));
	
	int i, j, k;
	int f;

	f = 1;
	for (i = 0; i <= 9; ++i) {
		a1[!f][i] = 1;
		a2[!f][i] = 1;
	}
	for (i = 2; i <= n; ++i) {
		a2[f][0] = 1;
		for (j = 1; j <= 9 * i; ++j) {
			a1[f][j] = 0;
			for (k = 1; k <= 9 && j - k >= 0; ++k) {
				if (j - k > 9 * (i - 1)) {
					continue;
				}
				a1[f][j] = (a1[f][j] + a2[!f][j - k]) % MOD;
			}
			a2[f][j] = (a1[f][j] + a2[!f][j]) % MOD;
		}
		f = !f;
	}
	f = !f;

	LL ans = 0;
	for (j = 1; j <= 9 * n; ++j) {
		ans = (ans + a1[f][j] * a2[f][j]) % MOD;
	}

	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld\n", solve(n));
	
	return 0;
}