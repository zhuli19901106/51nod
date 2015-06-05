#include <cstdio>
using namespace std;

typedef long long int LL;
const int N = 100000;
int n;
int a[N];

int main()
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
		
	LL n1 = 0;
	LL n2 = 0;
	for (i = 0; i < n; ++i) {
		if (a[i] == 1) {
			n1 += 1;
			continue;
		}
		if (a[i] == 2) {
			n2 += 1;
			continue;
		}
	}
	LL sum = 0;
	sum += n1 * (n1 - 1);
	sum += n2 * (n2 - 1) / 2;
	sum += n1 * (n - n1);
	printf("%lld\n", sum);
	
	return 0;
}