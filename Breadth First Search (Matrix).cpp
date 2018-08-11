/*
Luis Enrique Bernal Fuentes
Algorithm: Breadth First Search
Description:
*/

#include <cstdio>
#include <queue>

#define RANG 5010
using namespace std;

const int mf[4] = {1, -1, 0, 0},
	  	  mc[4] = {0, 0, 1, -1};
struct two {
	int f, c;

	two (int a = 0, int b = 0) {
		f = a;
		c = b;
	}
};
queue <two> Q;
int y, x, f, c, nf, nc, yend, xend, cost, q, C[RANG][RANG];
char A[RANG][RANG];

void BFS () {
	while (!Q.empty()) {
		f = Q.front().f;
		c = Q.front().c;
		Q.pop();
		cost = C[f][c] + 1;
		for (int i = 0; i < 4; i++) {
			nf = f + mf[i];
			nc = c + mc[i];
			if (A[nf][nc] == '.' && C[nf][nc] > cost) {
				C[nf][nc] = cost;
				Q.push (two (nf, nc));
			}
		}
	}
}

main() {
	freopen ("BFS.in", "r", stdin);
	freopen ("BFS.ou", "w", stdout);

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
		Q.push (two (y, x));
		BFS ();
		printf ("%d\n", C[yend][xend]);
	}
}
