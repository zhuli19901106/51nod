#include <cstdio>
using namespace std;

const int N = 55;
const int d[][2] = {{+1, 0}, {0, +1}};
int n, m;
char a[N][N];
int dj[N * N];

bool inbound(int x, int y)
{
    return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
}

int findRoot(int x)
{
    int r = x;
    while (r != dj[r]) {
        r = dj[r];
    }
    int k = x;
    while (x != r) {
        x = dj[x];
        dj[k] = r;
        k = x;
    }
    return r;
}

void solve()
{
    int i, j;
    for (i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (i = 0; i < n * m; ++i) {
        dj[i] = i;
    }
    
    int x, y;
    int r1, r2;
    int k;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            for (k = 0; k < 2; ++k) {
                x = i + d[k][0];
                y = j + d[k][1];
                if (!inbound(x, y) || a[i][j] != a[x][y]) {
                    continue;
                }
                r1 = findRoot(i * m + j);
                r2 = findRoot(x * m + y);
                if (r1 == r2) {
                    printf("Yes\n");
                    return;
                }
                dj[r2] = r1;
            }
        }
    }
    printf("No\n");
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2) {
        solve();
    }
    
    return 0;
}