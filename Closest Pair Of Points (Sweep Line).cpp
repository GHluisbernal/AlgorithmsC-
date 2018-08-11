/*
Luis Enrique Bernal Fuentes
Algorithm: Closest Pair Of Points
Description:
*/

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

#define RANG 1000010
#define oo 1 << 30
using namespace std;

struct two {
	double x, y;
} P[RANG], *last = P;

struct cmp_x {
    bool operator () (const two &p1, const two &p2) const {
        return p1.x < p2.x;
    }
};

struct cmp_y {
    bool operator () (const two &p1, const two &p2) const {
        return p1.y < p2.y;
    }
};

multiset <two, cmp_y> Q;
multiset <two, cmp_y>::iterator lo, hi;
double dsol = oo;
int l;

double dist (const two &p1, const two &p2) {
	return sqrt ((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));
}

main () {
	freopen ("CPP.in", "r", stdin);
	freopen ("CPP.ou", "w", stdout);

	scanf ("%d", &l);
	for (int i = 0; i < l; i++)
		scanf ("%lf %lf", &P[i].x, &P[i].y);

	sort (P, P + l, cmp_x());

	for (two *i = P; i < &P[l]; i++) {
        while (i -> x - last -> x >= dsol)
            Q.erase (Q.find (*last++));

        lo = Q.lower_bound ((two) {i -> x, i -> y - dsol});
        hi = Q.upper_bound ((two) {i -> x, i -> y + dsol});
		
        for (; lo != hi; lo++)
            dsol = min (dsol, dist (*lo, *i));
        Q.insert (*i);
	}

	printf ("%lf\n", dsol);
}
