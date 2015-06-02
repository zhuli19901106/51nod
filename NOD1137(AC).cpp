#include <cstdio>
using namespace std;

const int N = 100;
int a[N][N];
int b[N][N];
int c[N][N];

int main()
{
	int i, j, k;
	int n;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf("%d", &b[i][j]);
		}
	}
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (i = 0; i < n; ++i) {
		printf("%d", c[i][0]);
		for (j = 1; j < n; ++j) {
			printf(" %d", c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}