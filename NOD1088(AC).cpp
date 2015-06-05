// Brute-force solution
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int palindrome(char s[])
{
	int n = strlen(s);
	int ans = 0;
	
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 1; i - j  >= 0 && i + j <= n - 1; ++j) {
			if (s[i - j] != s[i + j]) {
				break;
			}
		}
		ans = max(ans, 2 * j - 1);
		for (j = 0; i - j  >= 0 && i + 1 + j <= n - 1; ++j) {
			if (s[i - j] != s[i + 1 + j]) {
				break;
			}
		}
		ans = max(ans, 2 * j);
	}
	
	return ans;
}

int main()
{
	char s[1005];
	
	gets(s);
	printf("%d\n", palindrome(s));
	
	return 0;
}