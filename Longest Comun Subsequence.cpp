/*
Luis Enrique Bernal Fuentes
Algorithm: Longest Comun Subsequence
Description:
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define RANG 100
using namespace std;

int lA, lB, T[RANG][RANG];
char A[RANG], B[RANG];

main() {
	//freopen ("LCS.in", "r", stdin);
	//freopen ("LCS.out", "w", stdout);

    scanf ("%s\n", A + 1);
	scanf ("%s", B + 1);

	lA = strlen (A + 1);
	lB = strlen (B + 1);
	for (int i = 1; i <= lB; i++)
		for (int j = 1; j <= lA; j++)
			if (B[i] == A[j])
				T[i][j] = T[i - 1][j - 1] + 1;
			else
				T[i][j] = max (T[i - 1][j], T[i][j - 1]);

	printf ("%d\n", T[lB][lA]);
}
