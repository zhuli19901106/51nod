// Simple binary search
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1005;
long long int a[N];
int n;

int main()
{
	int cc;
	int i, j, k;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	cc = 0;
	sort(a, a + n);
	for (i = 0; i < n - 2; ++i) {
		if (a[i] + a[i + 1] + a[i + 2] > 0) {
			break;
		}
		for (j = i + 1; j < n - 1; ++j) {
			if (a[i] + a[j] + a[j + 1] > 0) {
				break;
			}
			k = lower_bound(a + j + 1, a + n, -(a[i] + a[j])) - a;
			if (k == n || a[k] != -(a[i] + a[j])) {
				continue;
			}
			printf("%d %d %d\n", a[i], a[j], a[k]);
			++cc;
		}
	}
	if (cc == 0) {
		printf("No Solution\n");
	}
	
	return 0;
}