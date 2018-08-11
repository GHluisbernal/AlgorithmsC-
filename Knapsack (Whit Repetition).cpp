/*
Luis Enrique Bernal Fuentes
Algorithm: Knapsack
Description: 
*/

#include <cstdio>

#define RANG 5010
using namespace std;

int l, m, T[RANG], V[RANG], S[RANG];
bool M[RANG];

main () {
    freopen ("Knapsack.in", "r", stdin);
    freopen ("Knapsack.ou", "w", stdout);

    scanf ("%d %d", &m, &l);
    for (int i = 0; i < l; i++)
        scanf ("%d %d", &S[i], &V[i]);

	M[0] = true;
    for (int i = 0; i < l; i++)
        for (int j = S[i]; j <= m; j++)
			if (M[j - S[i]] && T[j] < T[j - S[i]] + V[i]) {
				M[j] = true;
				T[j] = T[j - S[i]] + V[i];
			}

    printf ("%d\n", T[m]);
}
