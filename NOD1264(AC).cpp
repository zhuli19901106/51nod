#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const double EPS = 1e-5;

typedef struct Point {
	double x, y;
} Point;

typedef struct Line {
	double a, b, c;
} Line;

void get_line(Point &p1, Point &p2, Line &l)
{
	l.a = p1.y - p2.y;
	l.b = p2.x - p1.x;
	l.c = p2.x * p1.y - p1.x * p2.y;
}

void intersect(Line &l1, Line &l2, Point &p)
{
	p.x = (l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b);
	p.y = (l1.a * l2.c - l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b);
}

bool between(Point &p1, Point &p2, Point &p)
{
	return p.x >= min(p1.x, p2.x) && p.x <= max(p1.x, p2.x) && 
	       p.y >= min(p1.y, p2.y) && p.y <= max(p1.y, p2.y);
}

int main()
{
	Point p1, p2, p3, p4;
	Point p;
	Line l1, l2;
	int t, ti;
	
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
		get_line(p1, p2, l1);
		get_line(p3, p4, l2);
		if (fabs(l1.a * l2.b - l2.a * l1.b) < EPS) {
			if (fabs(l1.a * l2.c - l2.a * l1.c) < EPS) {
				if (between(p1, p2, p3) || between(p1, p2, p4) || 
				    between(p3, p4, p1) || between(p3, p4, p2)) {
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			} else {
				printf("No\n");
			}
			continue;
		}
		intersect(l1, l2, p);
		if (between(p1, p2, p) && between(p3, p4, p)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}