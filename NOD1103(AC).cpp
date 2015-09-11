#include <cstdio>
#include <unordered_map>
using namespace std;

const int N = 50000;
int a[N];
int s[N + 1];
int n;

int main()
{
    scanf("%d", &n);
    s[0] = 0;
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        s[i + 1] = (s[i] + a[i]) % n;
    }
    unordered_map<int, int> um;
    int ll, rr;
    um[0] = 0;
    for (i = 1; i <= n; ++i) {
        if (um.find(s[i]) != um.end()) {
            ll = um[s[i]];
            rr = i;
            break;
        }
        um[s[i]] = i;
    }
    printf("%d\n", rr - ll);
    for (i = ll; i < rr; ++i) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}