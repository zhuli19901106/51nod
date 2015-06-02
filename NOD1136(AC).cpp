// Euler Function
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


int euler_function(int n)
{
	int i = 0;
	int sum = n;
	while (n / p[i] >= p[i]) {
		if (n % p[i]) {
			++i;
			continue;
		}
		sum = sum / p[i] * (p[i] - 1);
		while (n % p[i] == 0) {
			n /= p[i];
		}
		++i;
	}
	if (n > 1) {
		sum = sum / n * (n - 1);
	}
	return sum;
}

int main()
{
	sieve();
	
	int n;
	
	while (scanf("%d", &n) == 1) {
		printf("%d\n", euler_function(n));
	}
	
	return 0;
}