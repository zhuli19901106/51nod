#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007LL;
typedef vector<vector<LL> > V2DLL;

void matmult(V2DLL &a, V2DLL &b, V2DLL &c)
{
    int n = a.size();
    int i, j, k;
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (k = 0; k < n; ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
}

void matpow(V2DLL &m1, int p, V2DLL &res)
{
    int n = m1.size();
    // Here we assume p >= 1
    if (p == 1) {
        res = m1;
        return;
    }
    V2DLL m2(n, vector<LL>(n));
    matpow(m1, p >> 1, m2);
    if (p & 1) {
        V2DLL m3(n, vector<LL>(n));
        matmult(m2, m2, m3);
        matmult(m1, m3, res);
    } else {
        matmult(m2, m2, res);
    }
}

int main()
{
    V2DLL m, res;
    int n, p;
    
    scanf("%d%d", &n, &p);
    m.resize(n, vector<LL>(n));
    
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%lld", &m[i][j]);
        }
    }
    res.resize(n, vector<LL>(n));
    matpow(m, p, res);
    
    for (i = 0; i < n; ++i) {
        printf("%lld", res[i][0]);
        for (j = 1; j < n; ++j) {
            printf(" %lld", res[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}