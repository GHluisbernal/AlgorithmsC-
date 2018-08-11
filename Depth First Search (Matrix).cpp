/*
Luis Enrique Bernal Fuentes
Algorithm: Depth First Search
Description:
*/

#include <cstdio>
#include <algorithm>

#define RANG 5010
using namespace std;

const int mf[4] = {1, -1, 0, 0},
	  	  mc[4] = {0, 0, 1, -1};
int y, x, nf, nc, yend, xend, q, C[RANG][RANG];
char A[RANG][RANG];

void DFS (int f, int c) {
	int cost = C[f][c] + 1;
	for (int i = 0; i < 4; i++) {
		nf = f + mf[i];
		nc = c + mc[i];
		if (A[nf][nc] == '.' && C[nf][nc] > cost) {
			C[nf][nc] = cost;
			DFS (nf, nc);
		}
	}
}

main() {
	freopen ("DFS.in", "r", stdin);
	freopen ("DFS.ou", "w", stdout);

	scanf ("%d %d\n", &y, &x);
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++)
			scanf ("%c", &A[i][j]);
		scanf ("\n");
	}

	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d %d %d", &y, &x, &yend, &xend);
		memset (C, 63, sizeof (C));
		C[y][x] = 0;
		DFS (y, x);
		printf ("%d\n", C[yend][xend]);
	}
}
