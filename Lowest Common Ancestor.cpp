/*
Luis Enrique Bernal Fuentes
Algorithm: Lowest Common Ancestor
Description:
*/

#include <cstdio>
#include <vector>
#include <cmath>

#define RANG 100010
using namespace std;

vector <int> A[RANG];
int v, a, q, nod, newn, maxlog, LV[RANG], T[RANG][20];

void DFS (int nod, int lv) {
    LV[nod] = lv;
    maxlog = (int) log2 (lv);
    for (int i = 1; i <= maxlog; i++)
        T[nod][i] = T[T[nod][i - 1]][i - 1];

    for (vector <int>::iterator newn = A[nod].begin(); newn != A[nod].end(); newn++)
        DFS (*newn, lv + 1);
}

int search (int *nod, int *newn) {
    if (LV[*nod] < LV[*newn])
        swap (nod, newn);

    maxlog = (int) log2 (LV[*nod]);
    for (int i = maxlog; i >= 0; i--)
        if (LV[*nod] - (1 << i) >= LV[*newn])
            *nod = T[*nod][i];
    if (*nod == *newn)
	return *nod;

    maxlog = (int) log2 (LV[*nod]);
    for (int i = maxlog; i >= 0; i--)
        if (T[*nod][i] != T[*newn][i] && T[*nod][i]) {
            *nod = T[*nod][i];
            *newn = T[*newn][i];
        }
    return T[*nod][0];
}

main () {
	freopen ("LCA.in", "r", stdin);
	freopen ("LCA.ou", "w", stdout);

    scanf ("%d %d", &v, &a);
    for (int i = 0; i < a; i++) {
        scanf ("%d %d", &nod, &newn);
        A[nod].push_back (newn);
        T[newn][0] = nod;
    }

    DFS (1 , 1);

    scanf ("%d", &q);
    while (q--) {
        scanf ("%d %d", &nod, &newn);
        printf ("%d\n", search (&nod, &newn));
    }
}
