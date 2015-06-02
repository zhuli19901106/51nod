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

typedef struct Circle {
	Point p;
	double r;
} Circle;

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

double dist(Point &p1, Point &p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double line_dist(Point &p, Line &l)
{
	return fabs(l.a * p.x + l.b * p.y - l.c) / sqrt(l.a * l.a + l.b * l.b);
}

int main()
{
	Point p[3];
	Point pp;
	Circle c;
	Line l[3];
	Line pl;
	int t, ti;
	int cc;
	int i;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lf%lf%lf", &c.p.x, &c.p.y, &c.r);
		for (i = 0; i < 3; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for (i = 0; i < 3; ++i) {
			get_line(p[i], p[(i + 1) % 3], l[i]);
		}
		for (i = 0; i < 3; ++i) {
			if (fabs(dist(p[i], c.p) - c.r) < EPS) {
				//On the border
				break;
			}
		}
		if (i < 3) {
			printf("Yes\n");
			continue;
		}

		cc = 0;
		for (i = 0; i < 3; ++i) {
			if (dist(p[i], c.p) < c.r) {
				++cc;
			}
		}

		if (cc == 3) {
			printf("No\n");
			continue;
		}
		if (cc > 0) {
		    printf("Yes\n");
			continue;
		}
		for (i = 0; i < 3; ++i) {
			if (line_dist(c.p, l[i]) > c.r) {
				continue;
			}
			pl.a = l[i].b;
			pl.b = -l[i].a;
			pl.c = pl.a * c.p.x + pl.b * c.p.y;
			intersect(l[i], pl, pp);
			if (between(p[i], p[(i + 1) % 3], pp)) {
				break;
			}
		}
		if (i < 3) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}
