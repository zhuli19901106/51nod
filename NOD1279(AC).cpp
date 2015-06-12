#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 50000;
int a[N];
int d[N];
int n, m;

int solve()
{
	int i, j;
	int ans;
	
	for (i = 1; i < n; ++i) {
		a[i] = min(a[i], a[i - 1]);
	}
	j = n - 1;
	for (i = 0; i < m; ++i) {
		while (j >= 0 && a[j] < d[i]) {
			--j;
		}
		if (j < 0) {
			break;
		}
		++ans;
		--j;
	}
	return ans;
}

int main()
{
	int i;
	
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; ++i) {
		scanf("%d", &d[i]);
	}
	printf("%d\n", solve());
	
	return 0;
}