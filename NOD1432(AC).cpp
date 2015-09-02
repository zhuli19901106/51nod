#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

int main()
{
    int i, j;
    
    scanf("%d%d", &n, &m);
    v.resize(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    i = 0;
    j = n - 1;
    int ans = 0;
    while (i <= j) {
        if (i < j && v[i] + v[j] <= m) {
            ++i;
        }
        --j;
        ans += 1;
    }
    printf("%d\n", ans);
    
    return 0;
}