/*
Luis Enrique Bernal Fuentes
Algorithm: Edit Distance
Description:
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define RANG 5010
using namespace std;

int lA, lB, maxl, T[RANG][RANG];
char A[RANG], B[RANG];

main () {
	//freopen ("ED.in", "r", stdin);
	//freopen ("ED.ou", "w", stdout);

	scanf ("%s\n %s\n", A + 1, B + 1);

	lA = strlen (A + 1);
	lB = strlen (B + 1);
	maxl = max (lA, lB);
	for (int i = 0; i <= maxl; i++)
		T[i][0] = T[0][i] = i;
	for (int i = 1; i <= lA; i++)
		for (int j = 1; j <= lB; j++) {
			if (A[i] == B[j])
                T[i][j] = T[i - 1][j - 1];
            else
                T[i][j] = min (min (T[i][j - 1], T[i - 1][j]), T[i - 1][j - 1]) + 1;
		}

	printf ("%d\n", T[lA][lB]);
}
