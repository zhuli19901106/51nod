#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int LIS(vector<int> &a)
{
	int n = a.size();
	vector<int> v;
	int i, j;
	
	v.push_back(a[0]);
	for (i = 1; i < n; ++i) {
		if (a[i] < v[0]) {
			v[0] = a[i];
			continue;
		}
		if (a[i] > v.back()) {
			v.push_back(a[i]);
			continue;
		}
		j = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		v[j] = a[i];
	}
	
	n = v.size();
	v.clear();
	return n;
}

int main()
{
	const int N = 50000;
	vector<int> a;
	int n;
	int i;
	
	scanf("%d", &n);
	a.resize(n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", LIS(a));
	a.clear();
	
	return 0;
}