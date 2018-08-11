/*
Luis Enrique Bernal Fuentes
Algorithm: Floyd Warshall
Description: 
*/

#include <cstdio>
#include <algorithm>

#define RANG 310
using namespace std;

int v, a, q, nod, newn, cost, A[RANG][RANG];

main () {
	freopen ("FW.in", "r", stdin);
	freopen ("FW.ou", "w", stdout);
	
	memset (A, 63, sizeof (A));
	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod][newn] <?= cost;
	}
	
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			for (int k = 1; k <= v; k++)
				A[i][j] <?= A[i][k] + A[k][j];
	
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &nod, &newn);
		printf ("%d\n", A[nod][newn]);
	}
}
