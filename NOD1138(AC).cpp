#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

bool check(int x, int n, int &k)
{
	k = n / x - x + 1;
	return k % 2 == 0 && k > 0;
}

int main()
{
	int n;
	vector<int> v;
	
	int i, k;
	scanf("%d", &n);
	n *= 2;
	for (i = 2; i <= n / i; ++i) {
		if (n % i == 0) {
			if (check(i, n, k)) {
				v.push_back(k / 2);
			}
			if (check(n / i, n, k)) {
				v.push_back(k / 2);
			}
		}
	}
	sort(v.begin(), v.end());
	if (v.empty()) {
		printf("No Solution\n");
	} else {
		for (i = 0; i < v.size(); ++i) {
			printf("%d\n", v[i]);
		}
	}
	
	v.clear();
	
	return 0;
}