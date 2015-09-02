#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> xx, tt;

int myabs(int x)
{
    return x >= 0 ? x : -x;
}

int maxval(int x1, int x2, int t1, int t2)
{
    return max(t1, t2) + (myabs(x1 - x2) - myabs(t1 - t2)) / 2;
}

void solve()
{
    int xi, ti;
    int i, j;
    
    scanf("%d%d", &n, &m);
    xx.push_back(1);
    tt.push_back(0);
    for (i = 0; i < m; ++i) {
        scanf("%d%d", &xi, &ti);
        if (xi == 1) {
            continue;
        }
        xx.push_back(xi);
        tt.push_back(ti);
    }
    
    m = xx.size();
    for (i = 1; i < m; ++i) {
        for (j = 0; j < m; ++j) {
            if (j == i) {
                continue;
            }
            if (tt[i] - tt[j] > myabs(xx[i] - xx[j])) {
                tt[i] = tt[j] + myabs(xx[i] - xx[j]);
            }
        }
    }
    
    int ans = 0;
    for (i = 0; i < m - 1; ++i) {
        ans = max(ans, maxval(xx[i], xx[i + 1], tt[i], tt[i + 1]));
    }
    ans = max(ans, tt[i] + n - xx[i]);
    printf("%d\n", ans);

    xx.clear();
    tt.clear();
}

int main()
{
    int t, ti;
    
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        solve();
    }
    
    return 0;
}