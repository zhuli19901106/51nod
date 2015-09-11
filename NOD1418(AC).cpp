#include <cstdio>
using namespace std;

const int N = 55;
char s[N];
int c1[3], c2[3];
int cc1, cc2;
int idx[256];

void solve()
{
    int i;
    
    scanf("%s", s);
    cc1 = cc2 = 0;
    for (i = 0; i < 3; ++i) {
        c1[i] = c2[i] = 0;
    }
    
    int ans = 0;
    for (i = 0; s[i]; ++i) {
        ans += cc1 + cc2;
        if (c1[idx[s[i]]] == 0) {
            c1[idx[s[i]]] = 1;
            ++cc1;
        } else if(c2[idx[s[i]]] == 0) {
            c2[idx[s[i]]] = 1;
            ++cc2;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t, ti;
    
    idx['R'] = 0;
    idx['G'] = 1;
    idx['B'] = 2;
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        solve();
    }
    
    return 0;
}