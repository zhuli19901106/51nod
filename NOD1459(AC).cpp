// Dijkstra's Algorithm
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 1000000000;
const int N = 505;
int g[N][N];
int b[N], d[N], v[N], s[N];
int n, m;
int ss, ee;

int main()
{
    scanf("%d%d%d%d", &n, &m, &ss, &ee);
    int i, j, k;
    
    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        b[i] = 0;
        d[i] = INF;
        s[i] = 0;
        for (j = 0; j < n; ++j) {
            g[i][j] = INF;
        }
    }
    
    for (i = 0; i < m; ++i) {
        scanf("%d%d", &j, &k);
        scanf("%d", &g[j][k]);
        g[k][j] = g[j][k];
    }
    
    k = ss;
    b[k] = 1;
    d[k] = 0;
    s[k] = v[k];
    int k1;
    while (true) {
        for (i = 0; i < n; ++i) {
            if (b[i] || g[k][i] == INF) {
                continue;
            }
            if (d[k] + g[k][i] < d[i]) {
                d[i] = d[k] + g[k][i];
                s[i] = s[k] + v[i];
            } else if (d[k] + g[k][i] == d[i]) {
                s[i] = max(s[i], s[k] + v[i]);
            }
        }
        k1 = -1;
        for (i = 0; i < n; ++i) {
            if (b[i] || d[i] == INF) {
                continue;
            }
            if (k1 == -1 || d[i] < d[k1] || (d[i] == d[k1] && s[i] > s[k1])) {
                k1 = i;
            }
        }
        if (k1 == -1) {
            // No more updates
            break;
        }
        k = k1;
        b[k] = 1;
        k1 = -1;
    }
    printf("%d %d\n", d[ee], s[ee]);
    
    return 0;
}