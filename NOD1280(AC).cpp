#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int LL;
unordered_set<int> pre, sub;
unordered_set<int> dp, ds;
vector<int> v;
int n;
LL ans;
int i, j;
int i2, j2;

void findNextIdentical()
{
    int f;
    while (true) {
        f = ds.size() >= dp.size() ? 0 : 1;
        if (!(f ? j >= 0 : i <= n - 1)) {
            break;
        }
        switch (f) {
        case 0:
            if (ds.find(v[i]) != ds.end()) {
                ds.erase(v[i]);
            }
            if (sub.find(v[i]) == sub.end()) {
                dp.insert(v[i]);
                f = !f;
            } 
            pre.insert(v[i]);
            ++i;
            break;
        case 1:
            if (dp.find(v[j]) != dp.end()) {
                dp.erase(v[j]);
            }
            if (pre.find(v[j]) == pre.end()) {
                ds.insert(v[j]);
                f = !f;
            }
            sub.insert(v[j]);
            --j;
            break;
        }
        if (dp.size() == 0 && ds.size() == 0) {
            break;
        }
    }
    
    i2 = i;
    while (i2 <= n - 1 && pre.find(v[i2]) != pre.end()) {
        ++i2;
    }
    j2 = j;
    while (j2 >= 0 && sub.find(v[j2]) != sub.end()) {
        --j2;
    }
    ans += (i2 - i + 1) * (j - j2 + 1);
    i = i2;
    j = j2;
}

int main()
{
    scanf("%d", &n);
    v.resize(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    
    ans = 0;
    i = 0;
    j = n - 1;
    while (i <= n - 1 && j >= 0) {
        findNextIdentical();
    }
    printf("%lld\n", ans);
    
    return 0;
}