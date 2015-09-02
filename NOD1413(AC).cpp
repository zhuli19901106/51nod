#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int solve(int n)
{
    if (n == 0) {
        return 1;
    }
    
    char s[20];
    sprintf(s, "%d", n);
    n = strlen(s);
    int i;
    
    int ans = 0;
    for (i = 0; i < n; ++i) {
        ans = max(ans, s[i] - '0');
    }
    return ans;
}

int main()
{
    int n;
    
    scanf("%d", &n);
    printf("%d\n", solve(n));
    
    return 0;
}