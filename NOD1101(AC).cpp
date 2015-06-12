// Unbounded knapsack problem
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 100000;
const LL MOD = 1000000007;
LL a[N + 1];
int v[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int m = sizeof(v) / sizeof(int);

int main()
{
	memset(a, 0, sizeof(a));
	a[0] = 1;
	int i, j;
	for (i = 0; i < m; ++i) {
		for (j =v[i]; j <= N; ++j) {
			a[j] = (a[j] + a[j - v[i]]) % MOD;
		}
	}
	int n;
	
	scanf("%d", &n);
	printf("%lld\n", a[n]);
	
	return 0;
}