/*
Luis Enrique Bernal Fuentes
Algorithm: Acumulative Table
Description:
*/

#include <cstdio>

#define RANG 5010
using namespace std;

int y, x, xend, yend, sol, q, T[RANG][RANG];

main() {
	//freopen ("AT.in", "r", stdin);
	//freopen ("AT.ou", "w", stdout);

	scanf ("%d %d", &y, &x);
	for (int i = 1; i <= y; i++)
		for (int j = 1; j <= x; j++) {
			scanf ("%d", &T[i][j]);
			T[i][j] += T[i][j - 1] + T[i - 1][j] - T[i - 1][j - 1];
		}

	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d %d %d", &y, &x, &yend, &xend);
		sol = T[yend][xend] - T[yend][--x] - T[--y][xend] + T[y][x];
		printf ("%d\n", sol);
	}
}
