#include <cstdio>
#include <unordered_set>
using namespace std;

const int N = 20;
int a[N];
int n, k;

bool solve()
{
	int s = 0;
	int i;
	for (i = 0; i < n; ++i) {
		s += a[i];
	}
	if (k > s) {
		return false;
	}
	
	unordered_set<int> us[2];
	int f, nf;
	unordered_set<int>::iterator it;
	
	f = 0;
	for (i = 0; i < n; ++i) {
		us[f].clear();
		nf = !f;
		for (it = us[nf].begin(); it != us[nf].end(); ++it) {
			us[f].insert(*it + a[i]);
			us[f].insert(*it);
		}
		us[f].insert(a[i]);
		f = !f;
	}
	f = !f;
	bool res = us[f].find(k) != us[f].end();
	
	us[0].clear();
	us[1].clear();
	return res;
}

int main()
{
	int i;
	
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf(solve() ? "Yes\n" : "No\n");
	
	return 0;
}