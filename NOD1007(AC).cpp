#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;
const int M = 10000;
int a[N];
int b[M / 2 + 1];
int n;
int sum;

int main()
{
	int i, j;
	int sum;
	int half;
	
	scanf("%d", &n);
	sum = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	half = sum / 2;
	
	memset(b, 0, sizeof(b));
	b[0] = 1;
	for (i = 0; i < n; ++i) {
		for (j = half; j >= a[i]; --j) {
			if (b[j - a[i]]) {
				b[j] = 1;
			}
		}
	}
	i = half;
	while (!b[i]) {
		--i;
	}
	printf("%d\n", sum - 2 * i);
	
	return 0;
}