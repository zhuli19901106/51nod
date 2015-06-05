#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;

int main()
{
	LL i, p, a;
	vector<int> v;
	
	scanf("%lld%lld", &p, &a);
	for (i = 0; i <= p; ++i) {
		if (i * i % p == a) {
			v.push_back(i);
		}
	}
	if (v.empty()) {
		printf("No Solution\n");
	} else {
		printf("%lld", v[0]);
		for (i = 1; i < v.size(); ++i) {
			printf(" %lld", v[i]);
		}
		printf("\n");
	}
	v.clear();
	
	return 0;
}