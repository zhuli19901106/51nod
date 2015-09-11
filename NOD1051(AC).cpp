#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 505;
int n, m;
int a[N][N];
LL s[N + 1][N];
LL b[N];
LL ans;

LL maxSubarray(LL a[], int n)
{
    LL msum = 0;
    LL sum = 0;
    int i;
    
    for (i = 0; i < n; ++i) {
        sum += a[i];
        msum = max(msum, sum);
        sum = max(sum, 0LL);
    }
    return msum;
}

int main()
{
    scanf("%d%d", &m, &n);
    
    int i, j, k;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    memset(s, 0, sizeof(s));
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            s[i + 1][j] = s[i][j] + a[i][j];
        }
    }
    
    ans = 0;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j <= n; ++j) {
            for (k = 0; k < m; ++k) {
                b[k] = s[j][k] - s[i][k];
            }
            ans = max(ans, maxSubarray(b, m));
        }
    }
    printf("%lld\n", ans);
	
	return 0;
}