#include <cstdio>
using namespace std;

int main()
{
    int t, ti;
    double r;
    
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        scanf("%lf", &r);
        printf("%d\n", (int)(r * 2));
    }
    
    return 0;
}