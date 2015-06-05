// Count the number of ones from 1 to n
#include <cstdio>
using namespace std;

long long int sum[11];

long long int count_one(long long int x)
{
	long long int b10;
	int idx;

	if (x == 0) {
		return 0;
	} else if (x < 10) {
		return 1;
	}

	b10 = 1;
	idx = 0;
	while (b10 * 10 <= x) {
		b10 *= 10;
		++idx;
	}
	if (x / b10 > 1) {
		return (x / b10) * sum[idx] + b10 + count_one(x % b10);
	} else {
		return sum[idx] + (x % b10 + 1) + count_one(x % b10);
	}
}

int main()
{
	int i;
	int x;
	long long int b10;
	
	sum[0] = 0;
	sum[1] = 1;
	b10 = 1;
	for (i = 2; i <= 10; ++i) {
		b10 *= 10;
		sum[i] = 10 * sum[i - 1] + b10;
	}
	scanf("%d", &x);
	printf("%lld\n", count_one(x));
	
	return 0;
}