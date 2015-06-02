#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2000000;
int b[N + 1];
int p[100000];
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
	p[pc++] = 0;
	for (i = 0; i <= N; ++i) {
		b[i] = !b[i];
		if (b[i]) {
			p[pc++] = i;
		}
	}
}

int main()
{
	sieve();
	
	int n;
	
	scanf("%d", &n);
	int i = lower_bound(p, p + pc, n) - p;
	i = lower_bound(p, p + pc, i) - p;
	printf("%d\n", p[p[i]]);
	
	return 0;
}