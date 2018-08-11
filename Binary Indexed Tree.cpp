/*
Luis Enrique Bernal Fuentes
Algorithm: Binary Indexed Tree
Description:
*/

#include <cstdio>

#define RANG 1000010
using namespace std;

struct bit {
	int l, T[RANG], N[RANG];

	void add (int *x, int *n) {
		N[*x] += *n;
		for (int i = *x; i <= l; i += i & -i)
			T[i] += *n;
	}

	int sum (int *x) {
		int sum = 0;
		for (int i = *x; i; i -= i & -i)
			sum += T[i];
		return sum;
	}

	void update (int *x, int *n) {
		int sumx = *n - N[*x];
		add (x, &sumx);
	}
} BIT;
int q, x, n, sol;
char qt;

main() {
	//freopen ("BIT.in", "r", stdin);
	//freopen ("BIT.ou", "w", stdout);

	scanf ("%d %d\n", &BIT.l, &q);

	while (q--) {
		scanf ("%c ", &qt);
		if (qt == 'a') {
			scanf ("%d %d\n", &x, &n);
			BIT.add (&x, &n);
			continue;
		}
		if (qt == 'u') {
		    scanf ("%d %d\n", &x, &n);
			BIT.update (&x, &n);
			continue;
		}
		scanf ("%d %d\n", &x, &n);
		sol = BIT.sum (&n) - BIT.sum (&(--x));
		printf ("%d\n", sol);
	}
}
