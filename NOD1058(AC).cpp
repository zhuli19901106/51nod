#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1000000;
double a[N + 1];

int main()
{
	a[0] = 0;
	int i;
	for (i = 1; i <= N; ++i) {
		a[i] = a[i - 1] + log(1.0 * i);
	}
	
	while (scanf("%d", &i) == 1) {
		printf("%d\n", (int)(a[i] / log(10.0)) + 1);
	}
	
	return 0;
}