// Watch out for data scale
// Without 7
#include <cstdio>
using namespace std;

typedef long long int LL;
const int N = 1000000;
LL sum[N + 1];

bool contain_digit(int n, int d)
{
	while (n) {
		if (n % 10 == d) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main()
{
	LL i;

	sum[0] = 0;
	for (i = 1; i <= N; ++i) {
		sum[i] = sum[i - 1];
		if (i % 7 == 0) {
			continue;
		}
		if (contain_digit(i, 7)) {
			continue;
		}
		sum[i] += i * i;
	}
	
	int t, ti;
	int n;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		printf("%lld\n", sum[n]);
	}

	return 0;
}