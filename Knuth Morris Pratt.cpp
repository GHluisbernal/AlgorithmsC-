/*
Luis Enrique Bernal Fuentes
Algoritmo: Knuth Morris Pratt
Description:
*/

#include <cstdio>
#include <cstring>

#define RANG 1000010
using namespace std;

int lA, lB, mf, F[RANG];
char A[RANG], B[RANG];

main() {
    //freopen ("KMP.in", "r", stdin);
    //freopen ("KMP.ou", "w", stdout);

    scanf ("%s", A + 1);
    scanf ("%s", B + 1);

    lA = strlen (A + 1);
    lB = strlen (B + 1);

	//printf ("0 ");
	for (int i = 2; i <= lA; i++) {
		while (mf > 0 && A[i] != A[mf + 1])
			mf = F[mf];
		if (A[i] == A[mf + 1])
			mf++;
		F[i] = mf;
		//printf ("%d ", F[i]);
	}

	for (int i = 1, mf = 0; i <= lB; i++) {
		while (mf > 0 && A[mf + 1] != B[i])
		    mf = F[mf];
		if (A[mf + 1] == B[i])
			mf++;
		if (mf == lA) {
			printf ("%d\n", i - lA + 1);
			mf = F[mf];
		}
	}
}
