#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 50000;
LL a[N], dl[N], dr[N];
int n;

LL max_sum_1()
{
	// max subarray
	LL ans = 0;
	int i;
	LL sum;
	
	sum = 0;
	for (i = 0; i < n; ++i) {
		sum += a[i];
		ans = max(ans, sum);
		if (sum < 0) {
			sum = 0;
		}
	}
	return ans;
}

LL max_sum_2()
{
	// max subarray with two segments
	LL ans = 0;
	int i;
	LL sum;
	
	memset(dl, 0, sizeof(dl));
	memset(dr, 0, sizeof(dr));
	
	sum = dl[0] = a[0];
	for (i = 1; i <= n - 1; ++i) {
		sum += a[i];
		dl[i] = max(sum, dl[i - 1]);
	}
	
	sum = dr[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; --i) {
		sum += a[i];
		dr[i] = max(sum, dr[i + 1]);
	}
	for (i = 0; i < n - 1; ++i) {
		ans = max(ans, dl[i] + dr[i + 1]);
	}

	return ans;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	printf("%lld\n", max(max_sum_1(), max_sum_2()));
	
	return 0;
}