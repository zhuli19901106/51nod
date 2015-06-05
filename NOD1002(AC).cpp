// Triangle sum
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 500;
int a[N + 1][N + 1];
int m[N + 1][N + 1];
int n;
int msum;

int main()
{
	int i, j;
	
	scanf("%d", &n);
	msum = -1;
	for(i = 1; i <= n; ++i){
		for(j = 1; j <= i; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	m[1][1] = a[1][1];
	for(i = 2; i <= n; ++i){
		m[i][1] = m[i - 1][1] + a[i][1];
		m[i][i] = m[i - 1][i - 1] + a[i][i];
	}
	for(i = 3; i <= n; ++i){
		for(j = 2; j <= n - 1; ++j){
			m[i][j] = max(m[i - 1][j - 1], m[i - 1][j]) + a[i][j];
		}
	}
	msum = m[n][1];
	for (i = 2; i <= n; ++i) {
		msum = max(msum, m[n][i]);
	}
	printf("%d\n", msum);
	
	return 0;
}