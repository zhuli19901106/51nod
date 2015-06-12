#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct Term {
	int r, o;
} Term;
const int N = 100000;
Term a[N];
int n;

bool comp(const Term &t1, const Term &t2)
{
	// The key is here.
	// I just tried out every possibility and found this one.
	if (t1.r - t1.o != t1.r - t2.o) {
		return t1.r - t1.o > t2.r - t2.o;
	}
	if (t1.r != t2.r) {
		return t1.r > t2.r;
	}
	return false;
}

int main()
{
	int ans;
	int i;
	
	scanf("%d", &n);
	ans = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].r, &a[i].o);
		ans += a[i].o;
	}
	sort(a, a + n, comp);
	
	int sum = ans;
	for (i = 0; i < n; ++i) {
		if (sum >= a[i].r) {
			sum -= a[i].o;
		} else {
			ans += a[i].r - sum;
			sum = a[i].r - a[i].o;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}