#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
typedef struct Term {
    int x, w;
} Term;
vector<Term> v;
int n;
LL nn;
LL ans;

bool comp(const Term &t1, const Term &t2)
{
    return t1.x < t2.x;
}

int main()
{
    scanf("%d", &n);
    v.resize(n);
    
    int i;
    nn = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &v[i].x, &v[i].w);
        nn += v[i].w;
    }
    sort(v.begin(), v.end(), comp);
    
    int cx;
    LL sum = 0;
    for (i = 0; i < n; ++i) {
        if (nn / 2 >= sum && nn / 2 < sum + v[i].w) {
            cx = v[i].x;
            break;
        }
        sum += v[i].w;
    }
    
    ans = 0;
    for (i = 0; i < n; ++i) {
        ans += v[i].w * abs((LL)v[i].x - cx);
    }
    printf("%lld\n", ans);
    
    return 0;
}