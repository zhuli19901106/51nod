#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct Pair {
	int x, y;
} Pair;
const int N = 50000;
Pair a[N];
int n;

bool cmp(const Pair &p1, const Pair &p2)
{
	if (p1.x != p2.x) {
		return p1.x < p2.x;
	} else {
		return p1.y > p2.y;
	}
}

bool contain(const Pair &p1, const Pair &p2)
{
	return p1.x <= p2.x && p1.y >= p2.y;
}

int solve()
{
	int i, j;
	int ans = 0;
	
	i = 0;
	while (true) {
		j = i + 1;
		while (j < n && contain(a[i], a[j])) {
			ans = max(ans, a[j].y - a[j].x);
			++j;
		}
		if (j >= n) {
			break;
		}
		ans = max(ans, a[i].y - a[j].x);
		i = j;
	}
	
	return ans;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a + n, cmp);
	printf("%d\n", solve());
	
	return 0;
}