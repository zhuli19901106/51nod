// There's still an O(N) solution to figure out, not this one.
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 50005;
int a[N];
int b[N];
int n;
vector<int> p;
vector<int> d;
int cc;

bool check(int m)
{
    memset(b, 0, m * sizeof(int));
    cc = m;
    int sl = n / m;
    int i;
    for (i = 0; i < p.size(); ++i) {
        if (b[p[i] / sl] == 0) {
            --cc;
        }
        b[p[i] / sl] = 1;
    }
    return cc == 0;
}

int main()
{
    int i;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            p.push_back(i);
        }
    }
    i = 1;
    while (i <= n / i) {
        if (n % i) {
            ++i;
            continue;
        }
        d.push_back(i);
        if (i < n / i) {
            d.push_back(n / i);
        }
        ++i;
    }
    sort(d.begin(), d.end());
    
    for (i = d.size() - 1; i >= 0; --i) {
        if (check(d[i])) {
            break;
        }
    }
    printf("%d\n", i >= 0 ? d[i] : 0);
    
    return 0;
}