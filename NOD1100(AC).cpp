#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const double EPS = 1e-6;
typedef long long int LL;
typedef struct Term {
	LL x;
	LL y;
	int i;
} Term;
const int N = 10000;
Term a[N];
int n;

bool comp(const Term &t1, const Term &t2)
{
	if (t1.x != t2.x) {
		return t1.x < t2.x;
	}
	if (t1.y != t2.y) {
		return t1.y < t2.y;
	}
	return false;
}

int main()
{
	int i, j;
	int ii, jj;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
		a[i].i = i + 1;
	}
	sort(a, a + n, comp);
	double r, mr;
	
	mr = 1.0 * (a[1].y - a[0].y) / (a[1].x - a[0].x);
	for (i = 0; i < n - 1; ++i) {
		r = 1.0 * (a[i + 1].y - a[i].y) / (a[i + 1].x - a[i].x);
		if (fabs(r - mr) < EPS) {
			continue;
		}
		if (r > mr) {
			mr = r;
		}
	}
	i = 0;
	while (i < n - 1) {
		r = 1.0 * (a[i + 1].y - a[i].y) / (a[i + 1].x - a[i].x);
		if (fabs(r - mr) >= EPS) {
			++i;
			continue;
		}
		j = i + 1;
		while (j < n - 1) {
			r = 1.0 * (a[j + 1].y - a[j].y) / (a[j + 1].x - a[j].x);
			if (fabs(r - mr) >= EPS) {
				break;
			}
			++j;
		}
		for (ii = i; ii < j; ++ii) {
			for (jj = ii + 1; jj <= j; ++jj) {
				printf("%d %d\n", a[ii].i, a[jj].i);
			}
		}
		i = j;
	}
	
	return 0;
}