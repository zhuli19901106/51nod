#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 50005;
long long int a[N];
long long int k;
int n;

int main()
{
	int cc;
	int i, j;
	
	scanf("%lld%d", &k, &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	cc = 0;
	sort(a, a + n);
	for (i = 0; i < n - 1; ++i) {
		if (a[i] + a[i + 1] > k) {
			break;
		}
		j = lower_bound(a + i + 1, a + n, k - a[i]) - a;
		if (j == n || a[i] + a[j] != k) {
			continue;
		}
		printf("%lld %lld\n", a[i], a[j]);
		++cc;
	}
	if (cc == 0) {
		printf("No Solution\n");
	}
	
	return 0;
}