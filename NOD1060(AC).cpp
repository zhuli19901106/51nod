#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;
const LL N = 1000000000000000000LL;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
LL msum, mdc;

void DFS(int idx, LL sum, LL dc, int cr, LL n)
{
    if (dc > mdc) {
        mdc = dc;
        msum = sum;
    } else if (dc == mdc) {
        msum = min(msum, sum);
    }
    
    int r = 1;
    LL e = p[idx];
    while (n / e >= sum && r <= cr) {
        DFS(idx + 1, sum * e, dc * (r + 1), r, n);
        ++r;
        e *= p[idx];
    }
}

void solve(LL n)
{
    msum = mdc = 1;
    DFS(0, 1, 1, INT_MAX, n);
    printf("%lld %lld\n", msum, mdc);
}

int main()
{
    int t, ti;
    LL val;
    
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        scanf("%lld", &val);
        solve(val);
    }
    
    return 0;
}