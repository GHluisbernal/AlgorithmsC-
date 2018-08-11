/*
Luis Enrique Bernal Fuentes
Algorithm: Counting Change
Description:
*/

#include <cstdio>

#define RANG 5010
using namespace std;

int l, n, N[RANG], T[RANG];

main() {
	freopen ("CC.in", "r", stdin);
	freopen ("CC.ou", "w", stdout);

	scanf ("%d %d", &l, &n);
	for (int i = 0; i < l; i++)
		scanf ("%d", &N[i]);

    T[0] = 1;
	for (int i = 0; i < l; i++)
		for (int j = N[i]; j <= n; j++)
			T[j] += T[j - N[i]];

	printf ("%d\n", T[n]);
}
