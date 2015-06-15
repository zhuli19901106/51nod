#include <cstdio>
#include <queue>
using namespace std;

const int N = 50000;
int n;
int ans;

template<class T>
struct Cmp {
	bool operator () (const T &x, const T &y) const
	{
		return x > y;
	}
};

int main()
{
	int i;
	priority_queue<int, vector<int>, Cmp<int> > pq;
	int a1, a2;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a1);
		pq.push(a1);
	}
	ans = 0;
	for (i = 1; i < n; ++i) {
		a1 = pq.top();
		pq.pop();
		a2 = pq.top();
		pq.pop();
		ans += a1 + a2;
		pq.push(a1 + a2);
	}
	pq.pop();
	printf("%d\n", ans);
	
	return 0;
}