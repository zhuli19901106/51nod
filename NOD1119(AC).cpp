#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007LL;

void gcd(LL x, LL y, LL &a, LL &b)
{
    if (x == 0) {
        a = 0;
        b = 1;
        return;
    }
    gcd(y % x, x, a, b);
    LL tmp = a;
    a = b - y / x * a;
    b = tmp;
}

LL modinv(LL x, LL y)
{
    LL a, b;
    gcd(x, y, a, b);
    if (a < 0) {
        a = y - (y - a) % y;
    }
    return a % y;
}

LL comb(LL n, LL k, LL mod)
{
    if (n == 0 || k == 0) {
        return 1 % mod;
    }
    LL ans = 1;
    LL i;
    for (i = n - k + 1; i <= n; ++i) {
        ans = ans * i % MOD;
    }
    for (i = 1; i <= k; ++i) {
        ans = ans * modinv(i, MOD) % MOD;
    }
    return ans;
}

int main()
{
    LL m, n;
    
    scanf("%lld%lld", &m, &n);
    --m;
    --n;
    printf("%lld\n", comb(m + n, min(m, n), MOD));
    
    return 0;
}