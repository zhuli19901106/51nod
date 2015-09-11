#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 50005;
LL a[N], b[N];
LL n;
LL k;

LL count(LL mm)
{
    LL cc = 0;
    int i, j;

    j = n - 1;
    for (i = 0; i < n; ++i) {
        while (j >= 0 && a[i] * b[j] > mm) {
            --j;
        }
        cc += (j + 1);
    }
    return cc;
}

LL solve()
{
    LL ll = a[0] * b[0];
    LL rr = a[n - 1] * b[n - 1];
    LL mm;
    
    while (ll <= rr) {
        mm = (ll + rr) / 2;
        if (k <= count(mm)) {
            rr = mm - 1;
        } else {
            ll = mm + 1;
        }
    }
    return ll;
}

int main()
{
    int i;
    
    scanf("%lld%lld", &n, &k);
    k = n * n +1 - k;
    for (i = 0; i < n; ++i) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    printf("%lld\n", solve());
    
    return 0;
}