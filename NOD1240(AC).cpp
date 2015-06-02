#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 50000;
int b[N + 1];
int p[10000];
int pc;

void sieve()
{
	int i, j;
	
	memset(b, 0, sizeof(b));
	
	b[0] = b[1] = 1;
	for (i = 2; i <= N / i; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; j <= N / i; ++j) {
			b[i * j] = 1;
		}
	}
	
	pc = 0;
	for (i = 0; i <= N; ++i) {
		b[i] = !b[i];
		if (b[i]) {
			p[pc++] = i;
		}
	}
}

int mobius(int n)
{
	int ans = 1;
	int i;
	int c;
	
	i = 0;
	while (p[i] <= n / p[i]) {
		if (n % p[i] != 0) {
			++i;
			continue;
		}
		c = 0;
		while (n % p[i] == 0) {
			n /= p[i];
			++c;
		}
		if (c > 1) {
			return 0;
		}
		ans = -ans;
		++i;
	}
	if (n > 1) {
		ans = -ans;
	}
	return ans;
}

int main()
{
	sieve();
	
	int n;
	scanf("%d", &n);
	printf("%d\n", mobius(n));
	
	return 0;
}