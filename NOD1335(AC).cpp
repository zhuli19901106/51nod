#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int cn, ci;
    string s, s1;
    string ans;
    string ms;
    int i, j, n;
    char ch;
    int mx, my;
    
    cin >> cn;
    for (ci = 0; ci < cn; ++ci) {
        cin >> s;
        n = s.length();
        ms = s;
        for (i = n - 2; i >= 0; --i) {
            ms[i] = min(s[i], ms[i + 1]);
        }
        mx = my = -1;
        ans = s;
        for (i = 0; i < n; ++i) {
            if (s[i] != ms[i]) {
                break;
            }
        }
        for (j = i + 1; j < n; ++j) {
            if (s[j] != ms[i]) {
                continue;
            }
            s1 = s;
            reverse(s1.begin() + i, s1.begin() + j + 1);
            if (s1 < ans) {
                ans = s1;
                mx = i;
                my = j;
            }
        }
        if (mx == -1) {
            mx = my = 0;
        }
        printf("%d %d\n", mx, my);
    }
    
    return 0;
}