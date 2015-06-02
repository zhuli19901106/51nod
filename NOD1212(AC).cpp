#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1000;
const int M = 50000;
typedef struct Edge {
	int x, y, d;
} Edge;
Edge v[M];
int dj[N];
int n, m;

bool comp(const Edge &e1, const Edge &e2)
{
	return e1.d < e2.d;
}

int findRoot(int x)
{
	int r, k;

	r = x;
	while (r != dj[r]) {
		r = dj[r];
	}
	k = x;
	while (x != r) {
		x = dj[x];
		dj[k] = r;
		k = x;
	}
	return r;
}

int MST()
{
	int cc;
	int i;
	int rx, ry;
	int sum;

	for (i = 0; i < n; ++i) {
		dj[i] = i;
	}

	sum = 0;
	cc = 0;
	for (i = 0; i < m; ++i) {
		if (cc == n - 1) {
			return sum;
		}
		rx = findRoot(v[i].x);
		ry = findRoot(v[i].y);
		if (rx != ry) {
			dj[rx] = ry;
			sum += v[i].d;
			++cc;
		}
	}

	return -1;
}

int main()
{
	int i;

	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i) {
		scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].d);
		--v[i].x;
		--v[i].y;
	}
	sort(v, v + m, comp);
	printf("%d\n", MST());
	
	return 0;
}