// Yet to grasp the mechanism
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    double d = (sqrt(5.0) + 1.0) / 2.0;
    int t, ti;
    int a, b;
    
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        scanf("%d%d", &a, &b);
        if (a > b) {
            swap(a, b);
        }
        printf("%c\n", ((int)(a * d + 1) == b ? 'B' : 'A'));
    }
    
    return 0;
}