#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

typedef long long int LL;
const int N = 1000;
LL v[N];
int n;

bool four_sum(LL num[], int n, LL target)
{
	int a, b, c, d;
	LL s;
	
	// sort the array first
	sort(num, num + n);
	for (a = 0; a < n; ++a) {
		for (d = a + 3; d < n; ++d) {
			if (num[a] + num[d - 2] + num[d - 1] + num[d] < target) {
				// too small
				continue;
			}
			if (num[a] + num[a + 1] + num[a + 2] + num[d] > target) {
				// too large
				continue;
			}
			
			b = a + 1;
			c = d - 1;
			s = target - num[a] - num[d];
			while (true) {
				if (b >= c) {
					// edge is crossed
					break;
				}
				if (num[b] + num[c] < s) {
					++b;
				} else if (num[b] + num[c] > s) {
					--c;
				} else {
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &v[i]);
	}
	printf(four_sum(v, n, 0) ? "Yes\n" : "No\n");
	
	return 0;
}