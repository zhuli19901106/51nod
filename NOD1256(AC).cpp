#include <cstdio>
using namespace std;

int gcd(int x, int y, int &a, int &b)
{
	if (x == 0) {
		a = 0;
		b = 1;
		return y;
	}
	gcd(y % x, x, a, b);
	int tmp = a;
	a = b - y / x * a;
	b = tmp;
}

int main()
{
	int x, y, a, b;
	
	scanf("%d%d", &x, &y);
	gcd(x, y, a, b);
	
	a = a >= 0 ? a % y : (y - (y - a) % y) % y;
	printf("%d\n", a);
	
	return 0;
}