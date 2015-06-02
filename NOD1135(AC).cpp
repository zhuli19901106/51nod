#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
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

LL mypow(LL x, LL y, LL m)
{
	if (y == 0) {
		return 1 % m;
	}
	if (y == 1) {
		return x % m;
	}
	LL s = mypow(x, y >> 1, m);
	if (y & 1) {
		return s * s % m * x % m;
	} else {
		return s * s % m;
	}
}

int first_primitive_root(int n)
{
	int g;
	int f[100];
	int fc;
	int i;
	
	fc = 0;
	g = n - 1;
	i = 0;
	while (g / p[i] >= p[i]) {
		if (g % p[i]) {
			++i;
			continue;
		}
		f[fc++] = p[i];
		while (g % p[i] == 0) {
			g /= p[i];
		}
		++i;
	}
	if (g > 1) {
		f[fc++] = g;
	}
	
	g = 2;
	while (true) {
		for (i = 0; i < fc; ++i) {
			if (mypow(g, (n - 1) / f[i], n) == 1) {
				break;
			}
		}
		if (i == fc) {
			return g;
		}
		++g;
	}
}

int main()
{
	sieve();
	
	int n;
	
	while (scanf("%d", &n) == 1) {
		printf("%d\n", first_primitive_root(n));
	}
	
	return 0;
}