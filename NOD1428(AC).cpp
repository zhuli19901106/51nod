#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Term {
    int x, y;
    
    bool operator < (const Term &t) {
        if (x != t.x) {
            return x < t.x;
        } else if (y != t.y) {
            return y > t.y;
        }
        return true;
    }
} Term;
vector<Term> v;
int n;

int main()
{
    int start, end;
    int i;
    Term t;
    
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &start, &end);
        t.x = start;
        t.y = 0;
        v.push_back(t);
        t.x = end;
        t.y = 1;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    
    int st = 0;
    int ans = 0;
    for (i = 0; i < 2 * n; ++i) {
        if (v[i].y == 0) {
            ++st;
        } else {
            --st;
        }
        ans = max(ans, st);
    }
    printf("%d\n", ans);
    
    return 0;
}