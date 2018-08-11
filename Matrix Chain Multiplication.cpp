/*
Luis Enrique Bernal Fuentes
Algorithm: Matrix Chain Multiplication
Description:
*/

#include <cstdio>

#define RANG 5010
#define oo 1 << 30
using namespace std;

int l, end, cost, F[RANG], C[RANG], T[RANG][RANG], P[RANG][RANG];

main () {
	freopen ("MCM.in", "r", stdin);
	freopen ("MCM.ou", "w", stdout);

	scanf ("%d", &l);
	for (int i = 1; i <= l; i++)
		scanf ("%d %d", &F[i], &C[i]);

	for (int i = 2; i <= l; i++)
		for (int j = 1; j <= l - i+1; j++) {
			end = j + i - 1;
			T[j][end] = oo;
			for (int k = j; k < end; k++) {
				cost = T[j][k] + T[k + 1][end] + F[j] * C[k] * C[end];
				if (T[j][end] > cost) {
					T[j][end] = cost;
					P[i][j] = k;
				}
			}
		}

	printf ("%d %d\n", T[1][l], P[1][l]);
}
