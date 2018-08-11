/*
Luis Enrique Bernal Fuentes
Algorithm: Segment Tree
Description:
*/

#include <cstdio>
#include <algorithm>

#define RANG 1000010
#define oo 1 << 30
using namespace std;

int a, b, q, N[RANG];
char qt;

struct st {
	int l, T[RANG];

	int build (int x, int xend, int lv) {
		if (x == xend)
			return T[lv] = N[x];
		int piv = (x + xend) / 2;
		return T[lv] = min (build (x, piv, lv * 2), build (piv + 1, xend, lv * 2 + 1));
	}

	int update (int x, int xend, int lv) {
        if (x > a || xend < a)
            return T[lv];
        if (x == xend)
            return N[x];
        int piv = (x + xend) / 2;
        return T[lv] = min (update (x, piv, lv * 2), update (piv + 1, xend, lv * 2 + 1));
	}

	int query (int x, int xend, int lv) {
		if (a > xend || b < x)
			return oo;
		if (a <= x && b >= xend)
			return T[lv];
		int piv = (x + xend) / 2;
		return min (query (x, piv, lv * 2), query (piv + 1, xend, lv * 2 + 1));
	}
} ST;

main () {
	freopen ("ST.in", "r", stdin);
	freopen ("ST.ou", "w", stdout);

	scanf ("%d", &ST.l);
	for (int i = 1; i <= ST.l; i++)
		scanf ("%d", &N[i]);

	ST.build (1, ST.l, 1);

	scanf ("%d\n", &q);
	while (q--) {
		scanf ("%c %d %d\n", &qt, &a, &b);
		if (qt == 'q')
            printf ("%d\n", ST.query (1, ST.l, 1));
        else {
            N[a] = b;
            ST.update (1, ST.l, 1);
        }
	}
}
