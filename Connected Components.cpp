/*
Luis Enrique Bernal Fuentes
Algorithm: Connected Components (Undirected Graph)
Description:
*/

#include <cstdio>
#include <vector>

#define RANG 1000010
using namespace std;

vector <int> A[RANG];
int v, a, nod, newn;
bool MK[RANG];

void DFS (int nod) {
    MK[nod] = true;
	for (vector <int>::iterator i = A[nod].begin(); i != A[nod].end(); i++)
        if (!MK[*i])
            DFS (*i);
    printf ("%d ", nod);
}

main() {
    freopen ("CC.in", "r", stdin);
    freopen ("CC.ou", "w", stdout);

    scanf ("%d %d", &v, &a);
    for (int i = 1; i <= a; i++) {
        scanf ("%d %d", &nod, &newn);
        A[nod].push_back (newn);
    }

	for (int i = 1; i <= v; i++)
		if (!MK[i]) {
            DFS (i);
            printf ("\n");
		}
}
