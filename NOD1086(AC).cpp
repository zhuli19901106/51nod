#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1005;
const int W = 50005;
int w[N];
int p[N];
int m;
int dp[W];
int n, tw;

void splitItem(int ww, int pp, int cc)
{
    int i = 1;
    while (cc > 0) {
        if (cc <= i) {
            w[m] = ww * cc;
            p[m] = pp * cc;
            cc = 0;
        } else {
            w[m] = ww * i;
            p[m] = pp * i;
            cc -= i;
            i <<= 1;
        }
        ++m;
    }
}

int main()
{
    scanf("%d%d", &n, &tw);
    int ww, pp, cc;
    int i, j;
    
    m = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d%d%d", &ww, &pp, &cc);
        splitItem(ww, pp, cc);
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (i = 0; i < m; ++i) {
        for (j = tw; j >= w[i]; --j) {
            if (dp[j - w[i]] < 0) {
                continue;
            }
            dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        }
    }
    
    int ans = 0;
    for (i = 0; i <= tw; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    
    return 0;
}