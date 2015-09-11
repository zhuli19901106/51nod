#include <cstdio>
using namespace std;

int main()
{
    int val;
    int sum;
    int n, i;
    
    scanf("%d", &n);
    sum = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d", &val);
        sum ^= val;
    }
    printf("%c\n", (sum ? 'A' : 'B'));
    
    return 0;
}