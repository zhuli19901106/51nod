#include <cstdio>
using namespace std;

typedef long long int LL;

int main()
{
	int n, p;
	LL sum = 1;
	
	scanf("%d%d", &n, &p);
	int i;
	for (i = 1; i <= n; ++i) {
		sum = sum * i % p;
	}
	printf("%lld\n", sum);
	
	return 0;
}