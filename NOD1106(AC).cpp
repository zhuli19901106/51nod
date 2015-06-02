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

bool isprime(int n)
{
	if (n < 2) {
		return false;
	}
	int i = 0;
	while (p[i] <= n / p[i]) {
		if (n % p[i] == 0) {
			return false;
		}
		++i;
	}
	return true;
}

int main()
{
	sieve();
	
	int t, ti;
	int n;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		printf(isprime(n) ? "Yes\n" : "No\n");
	}
	
	return 0;
}