#include <cmath>
#include <cstdio>
using namespace std;

const double EPS = 1e-5;

double det(double a[3][3])
{
	return a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + 
		   a[0][2] * a[1][0] * a[2][1] - a[0][0] * a[1][2] * a[2][1] - 
		   a[0][1] * a[1][0] * a[2][2] - a[0][2] * a[1][1] * a[2][0];
}

int main()
{
	double a[3][3];
	double p[4][3];
	int t, ti;
	int i;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		for (i = 0; i < 4; ++i) {
			scanf("%lf%lf%lf", &p[i][0], &p[i][1], &p[i][2]);
		}
		for (i = 0; i < 3; ++i) {
			a[i][0] = p[i + 1][0] - p[0][0];
			a[i][1] = p[i + 1][1] - p[0][1];
			a[i][2] = p[i + 1][2] - p[0][2];
		}
		if (fabs(det(a)) < EPS) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}