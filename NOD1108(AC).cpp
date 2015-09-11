#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

typedef long long int LL;
vector<vector<int> > v;
LL ans;
int n;

int main()
{
    scanf("%d", &n);
    v.resize(3, vector<int>(n));
    
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < 3; ++j) {
            scanf("%d", &v[j][i]);
        }
    }
    for (i = 0; i < 3; ++i) {
        sort(v[i].begin(), v[i].end());
    }

    ans = 0;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < n; ++j) {
            ans += abs(v[i][j] - v[i][n / 2]);
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}