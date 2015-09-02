#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 1000005;
char s[N];
unordered_map<int, int> um;
int n;

int main()
{
    gets(s);
    n = strlen(s);
    
    int val = 0;
    int ans = 0;
    
    um[val] = 0;
    int i;
    for (i = 0; i < n; ++i) {
        val += s[i] == '0' ? -1 : 1;
        if (um.find(val) != um.end()) {
            ans = max(ans, i + 1 - um[val]);
        } else {
            um[val] = i + 1;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}