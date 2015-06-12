// My solution on leetcode
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;
class Solution {
public:
	LL largestRectangleArea(vector<LL> &height) {
		int i;
		int n;
		
		n = (int)height.size();
		if (n == 0) {
			return 0;
		}
		
		vector<int> ll, rr;
		LL max_area = 0;
		LL area = 0;
		
		ll.resize(n);
		rr.resize(n);
		for (i = 0; i < n; ++i) {
			ll[i] = i;
			rr[i] = i;
		}
		for (i = 0; i <= n - 1; ++i) {
			while (ll[i] - 1 >= 0 && height[ll[i] - 1] >= height[i]) {
				ll[i] = ll[ll[i] - 1];
			}
		}
		for (i = n - 1; i >= 0; --i) {
			while (rr[i] + 1 <= n - 1 && height[rr[i] + 1] >= height[i]) {
				rr[i] = rr[rr[i] + 1];
			}
		}
		
		for (i = 0; i < n; ++i) {
			area = (rr[i] - ll[i] + 1) * height[i];
			if (area > max_area) {
				max_area = area;
			}
		}
		
		ll.clear();
		rr.clear();
		return max_area;
	}
};

int main()
{
	Solution sol;
	int n;
	int i;
	vector<LL> v;
	
	scanf("%d", &n);
	v.resize(n);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &v[i]);
	}
	printf("%lld\n", sol.largestRectangleArea(v));
	
	return 0;
}