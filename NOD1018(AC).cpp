#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	const int N = 50005;
	int n, i;
	int *a = new int[N];
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (i = 0; i < n; ++i) {
		printf("%d\n", a[i]);
	}
	
	delete[] a;
	
	return 0;
}