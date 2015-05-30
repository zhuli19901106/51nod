// Binary indexed tree.
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 50000;
LL a[N + 1];
int n;
int q;

int lowbit(int x)
{
	return x & -x;
}

void add(int i, LL c)
{
	while (i <= n) {
		a[i] += c;
		i += lowbit(i);
	}
}

LL sum(int i)
{
	LL s = 0;
	while (i > 0) {
		s += a[i];
		i -= lowbit(i);
	}
	return s;
}

LL sum(int i, int j)
{
	return sum(j) - sum(i - 1);
}

int main()
{
	memset(a, 0, sizeof(a));
	int i;
	LL val;
	
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%lld", &val);
		add(i, val);
	}
	int x, y;
	scanf("%d", &q);
	for (i = 1; i <= q; ++i) {
		scanf("%d%d", &x, &y);
		printf("%lld\n", sum(x, x + y - 1));
	}
	
	return 0;
}