// Count the number of ones from 1 to n
#include <cstdio>
using namespace std;

typedef long long int LL;
const int M = 19;
LL sum[19];
LL sum0[19];

LL leading_zero(LL x, int idx)
{
	LL b10 = 1;
	LL sum = idx;
	int bi = 1;
	while (b10 * 10 <= x) {
		sum += 9 * b10 * (idx - bi);
		b10 *= 10;
		++bi;
	}
	sum += (x - b10 + 1) * (idx - bi);
	return sum;
}

LL count_zero(LL x)
{
	LL b10;
	int idx;
	
	if (x < 10) {
		return 0;
	}

	b10 = 1;
	idx = 0;
	while (b10 * 10 <= x) {
		b10 *= 10;
		++idx;
	}

	LL ans = 0;
	LL ss = 0;
	int i;

	for (i = 1; i <= idx; ++i) {
		ans += sum0[i];
		ss += sum0[i];
	}
	ans += (x / b10 - 1) * (ss + leading_zero(b10 - 1, idx));
	ans += leading_zero(x % b10, idx) + count_zero(x % b10);

	return ans;
}

LL count_digit(LL x, int d)
{
	LL b10;
	int idx;

	if (x < d) {
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
	if (x / b10 > d) {
		return (x / b10) * sum[idx] + b10 + count_digit(x % b10, d);
	} else if (x / b10 == d) {
		return (x / b10) * sum[idx] + (x % b10 + 1) + count_digit(x % b10, d);
	} else {
		return (x / b10) * sum[idx] + count_digit(x % b10, d);
	}
}

int cz(int x)
{
	int cc = 0;
	while (x) {
		if (x % 10 == 0) {
			++cc;
		}
		x /= 10;
	}
	return cc;
}

int main()
{
	int i, j;
	LL x, y;
	LL b10;
	
	sum[0] = 0;
	sum[1] = 1;
	b10 = 1;
	for (i = 2; i < M; ++i) {
		b10 *= 10;
		sum[i] = 10 * sum[i - 1] + b10;
	}
	
	LL ss;

	sum0[0] = 0;
	sum0[1] = 0;
	b10 = 1;
	for (i = 2; i < M; ++i) {
		b10 *= 10;
		ss = 0;
		for (j = 1; j < i; ++j) {
			ss += sum0[j];
		}
		sum0[i] = 9 * (leading_zero(b10 - 1, i - 1) + ss);
	}
	
	while (scanf("%lld%lld", &x, &y) == 2) {
		printf("%lld\n", count_zero(y) - count_zero(x - 1));
		for (i = 1; i <= 9; ++i) {
			printf("%lld\n", count_digit(y, i) - count_digit(x - 1, i));
		}
	}
	
	return 0;
}