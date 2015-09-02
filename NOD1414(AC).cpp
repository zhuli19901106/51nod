#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 20005;
int n;
int a[N];
int ans;

int test(int p)
{
    if (n / p < 3) {
        return INT_MIN;
    }
    
    int i, j;
    int ans = INT_MIN;
    int sum = 0;
    
    for (i = 0; i < p; ++i) {
        sum = 0;
        for (j = i; j < n; j += p) {
            sum += a[j];
        }
        ans = max(ans, sum);
    }
    
    return ans;
}

int main()
{
    int i;
    
    scanf("%d", &n);
    ans = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ans += a[i];
    }
    
    for (i = 1; i <= n / i; ++i) {
        if (n % i) {
            continue;
        }
        ans = max(ans, test(i));
        if (i == n / i) {
            continue;
        }
        ans = max(ans, test(n / i));
    }
    printf("%d\n", ans);
    
    return 0;
}