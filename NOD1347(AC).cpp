#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000000;
char s[N + 1];

bool check(char s[])
{
	int n = strlen(s);
	
	if (n & 1) {
		return false;
	}
	n >>= 1;
	int i;
	for (i = 0; i < n; ++i) {
		if (s[i] != s[i + n]) {
			return false;
		}
	}
	return true;
}

int main()
{
	while (gets(s) != NULL) {
		printf(check(s) ? "YES\n" : "NO\n");
	}
	
	return 0;
}