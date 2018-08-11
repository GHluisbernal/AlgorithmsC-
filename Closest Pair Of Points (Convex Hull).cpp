/*
Luis Enrique Bernal Fuentes
Algorithm: Closest Pair Of Points
Description:
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

#define RANG 1000010
#define oo 1 << 30
using namespace std;

struct two {
	double x, y;
	
	bool operator < (const two &p) const {
		if (x != p.x)
			return x < p.x;
		return y < p.y;
	}
} P[RANG], T[RANG];
int l, lim = 1, top;
double dsol = oo;

double cross (const two &pf, const two &p1, const two &p2) {
	double m1 = (p2.y - pf.y) * (p1.x - pf.x);
	double m2 = (p2.x - pf.x) * (p1.y - pf.y);
	return m1 - m2;
}

double dist (const two &p1, const two &p2) {
	return sqrt ((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}

main () {
	freopen ("CPP.in", "r", stdin);
	freopen ("CPP.ou", "w", stdout);
	
	scanf ("%d", &l);
	for (int i = 0; i < l; i++)
		scanf ("%lf %lf", &P[i].x, &P[i].y);
	
	sort (P, P + l);
	
	T[++top] = P[0];
	T[++top] = P[1];
	for (int i = 2; i < l; i++) {
		while (top > lim && cross (T[top - 1], T[top], P[i]) < 0)
			top--;
		T[++top] = P[i];
		dsol = min (dsol, dist (T[top - 1], T[top]));
	}
	
	lim = top;
	T[++top] = T[l - 2];
	T[++top] = T[l - 3];
	for (int i = l - 4; i >= 0; i--) {
		while (top > lim && cross (T[top - 1], T[top], P[i]) < 0)
			top--;
		T[++top] = P[i];
		dsol = min (dsol, dist (T[top - 1], T[top]));
	}
	
	printf ("%lf\n", dsol);
}
