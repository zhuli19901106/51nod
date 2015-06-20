// O(n) solution
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v1, v2;
const int N = 50000;
int a[N];
int n;

int solve()
{
	int i;
	
	v1.push_back(0);
	for (i = 1; i <= n - 1; ++i) {
		if (a[i] <= a[v1.back()]) {
			v1.push_back(i);
		}
	}
	v2.push_back(n - 1);
	for (i = n - 2; i >= 0; --i) {
		if (a[i] >= a[v2.back()]) {
			v2.push_back(i);
		}
	}
	
	int s1, s2;
	int j;
	int ans = 0;
	
	s1 = v1.size();
	s2 = v2.size();
	j = s2 - 1;
	for (i = 0; i < s1; ++i) {
		while (j >= 0 && a[v1[i]] <= a[v2[j]]) {
			ans = max(ans, v2[j--] - v1[i]);
		}
	}
	v1.clear();
	v2.clear();
	return ans;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", solve());
	
	return 0;
}