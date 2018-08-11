/*
Luis Enrique Bernal Fuentes
Algorithm: Convex Hull (Graham Scan)
Descriptions:
*/

#include <cstdio>
#include <algorithm>

#define RANG 100010
using namespace std;

double x, y;
int l, top, lim = 1;

struct two {
	double x, y;

	bool operator < (const two &p) const {
		if (x != p.x)
			return x < p.x;
		return y < p.y;
	}
} P[RANG], T[RANG];

double cross (const two &pf, const two &p1, const two &p2) {
	double m1 = (p2.y - pf.y) * (p1.x - pf.x);
	double m2 = (p2.x - pf.x) * (p1.y - pf.y);
	return m1 - m2;
}

main () {
	freopen ("convex_hull.in", "r", stdin);
	freopen ("convex_hull.ou", "w", stdout);

	scanf ("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf ("%lf %lf", &x, &y);
		P[i] = (two) {x, y};
	}

	sort (P, P + l);

	for (int i = 0; i < l; i++) {
		while (top > lim && cross (T[top - 1], T[top], P[i]) <= 0)
			top--;
		T[++top] = P[i];
	}

    lim = top;
    for (int i = l - 1; i >= 0; i--) {
        while (top > lim && cross (T[top - 1], T[top], P[i]) <= 0)
			top--;
		T[++top] = P[i];
    }

	printf ("%d\n", top);
	for (int i = 1; i <= top; i++)
	    printf ("%.0lf %.0lf\n", T[i].x, T[i].y);
}
