#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i, n;
	int len;
	int pos;
	int max_t, min_t;
	int max_pos;
	int min_pos;
	int mid_pos;
	int mid;
	
	max_t = INT_MIN;
	min_t = INT_MAX;
	max_pos = INT_MIN;
	min_pos = INT_MAX;
	mid_pos = -1;
	scanf("%d%d", &n, &len);
	mid = len / 2;
	for(i = 0; i < n; ++i){
		scanf("%d", &pos);
		min_pos = min(min_pos, pos);
		max_pos = max(max_pos, pos);
		if(abs(pos - mid) < abs(mid_pos - mid)){
			mid_pos = pos;
		}
	}
	
	min_t = mid - abs(mid_pos - mid);
	max_t = max_pos > len - min_pos ? max_pos : len - min_pos;
	printf("%d %d\n", min_t, max_t);
	
	return 0;
}