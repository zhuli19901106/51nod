// 1AC
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100000;
char s[N + 1];
int n;
int c[26];
int cc;

void solve()
{
	int i, j;
	int ans;
	
	memset(c, 0, sizeof(c));
	cc = 0;
	ans = INT_MAX;
	i = j = 0;
	while (i < n) {
		while (j < n && cc < 26) {
			if (c[s[j] - 'A'] == 0) {
				++cc;
			}
			++c[s[j] - 'A'];
			++j;
		}
		if (cc < 26) {
			break;
		}
		do {
			ans = min(ans, j - i);
			if (c[s[i] - 'A'] == 1) {
				--cc;
			}
			--c[s[i++] - 'A'];
		} while (cc == 26);
	}
	
	if (ans != INT_MAX) {
		printf("%d\n", ans);
	} else {
		printf("No Solution\n");
	}
}

int main()
{
	gets(s);
	n = strlen(s);
	solve();
	
	return 0;
}