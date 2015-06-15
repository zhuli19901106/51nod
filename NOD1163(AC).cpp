#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long int LL;
const int N = 50000;
typedef struct Term {
	int e;
	int w;
} Term;
Term a[N];
int n;
LL ans;

bool comp(const Term &t1, const Term &t2)
{
	if (t1.e != t2.e) {
		return t1.e < t2.e;
	} else {
		return t1.w > t2.w;
	}
}

int main()
{
	int i, j;
	int cc;
	priority_queue<int, vector<int>,  greater<int> > pq;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].e, &a[i].w);
	}
	sort(a, a + n, comp);
	cc = 0;
	i = 0;
	while (i < n) {
		j = i;
		while (j < n && a[j].e == a[i].e) {
			if (cc < a[i].e) {
				pq.push(a[j++].w);
				++cc;
				continue;
			}
			if (pq.top() < a[j].w) {
				pq.pop();
				pq.push(a[j].w);
			}
			++j;
		}
		i = j;
	}
	ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	
	printf("%lld\n", ans);
	
	return 0;
}