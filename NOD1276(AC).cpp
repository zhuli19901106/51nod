#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int n, q;
vector<int> p, t;// p for peak, t for trough

int main()
{
    int i, j;
    
    scanf("%d%d", &n, &q);
    v.resize(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    int m = 0;
    i = 0;
    while (i < n) {
        j = i + 1;
        while (j < n && v[i] == v[j]) {
            ++j;
        }
        v[m++] = v[i];
        i = j;
    }
    v.resize(m);
    n = v.size();
    
    bool lp, rp;
    for (i = 0; i < n; ++i) {
        lp = rp = true;
        if (i > 0 && v[i] < v[i - 1]) {
            lp = false;
        }
        if (i < n - 1 && v[i] < v[i + 1]) {
            rp = false;
        }
        if (lp && rp) {
            p.push_back(v[i]);
        }
        if (!(lp || rp)) {
            t.push_back(v[i]);
        }
    }
    sort(p.begin(), p.end());
    sort(t.begin(), t.end());
    
    int val;
    int ip, it;
    for (i = 0; i < q; ++i) {
        scanf("%d", &val);
        ip = upper_bound(p.begin(), p.end(), val) - p.begin();
        it = upper_bound(t.begin(), t.end(), val) - t.begin();
        printf("%d\n", 1 + it - ip);
    }
    
    return 0;
}