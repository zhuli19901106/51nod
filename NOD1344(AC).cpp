#include <cstdio>
using namespace std;

typedef long long int LL;

int main()
{
	const int N = 50000;
	int a[N];
	int n;
	LL sum;
	LL ans;
	
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	ans = sum = 0;
	for (i = 0; i < n; ++i) {
		sum += a[i];
		if (sum < 0) {
			ans -= sum;
			sum = 0;
		}
	}
	printf("%lld\n", ans);
	
	return 0;
}