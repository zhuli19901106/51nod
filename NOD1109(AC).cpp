#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int N = 1000000;
// bt for backtrace
int r[N];
int bt[N + 1];
int n;

void solve()
{
    if (n == 1) {
        printf("1\n");
        return;
    }
    
    int i;
    r[0] = 1;
    for (i = 1; i < n; ++i) {
        r[i] = (r[i - 1] * 10) % n;
        if (r[i] == 0) {
            r[i] += n;
        }
    }
    
    memset(bt, -1, sizeof(bt));
    int w;
    int j, k;
    
    bt[0] = 0;
    for (i = 0; i < n; ++i) {
        w = r[i];
        for (j = n + w; j >= w; --j) {
            if (bt[j - w] == -1) {
                continue;
            }
            if (bt[j - w] == i + 1) {
                continue;
            }
            k = j % n;
            k = k ? k : n;
            if (bt[k] == -1) {
                bt[k] = i + 1;
            }
        }
        if (bt[n] != -1) {
            break;
        }
    }
    
    vector<int> one;
    w = n;
    while (bt[w] != 0) {
        one.push_back(bt[w] - 1);
        w = (w + n - r[bt[w] - 1]) % n;
    }
    string ans = "";
    ans.push_back('1');
    for (i = 0; i < one.size() - 1; ++i) {
        for (j = one[i] - 1; j >= one[i + 1] + 1; --j) {
            ans.push_back('0');
        }
        ans.push_back('1');
    }
    for (j = one[i] - 1; j >= 0; --j) {
        ans.push_back('0');
    }
    printf("%s\n", ans.data());
}

int main()
{
    while (scanf("%d", &n) == 1) {
        solve();
    }
    
    return 0;
}