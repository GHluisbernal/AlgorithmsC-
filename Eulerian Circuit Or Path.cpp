/*
Luis Enrique Bernal Fuentes
Algorithm: Eulerian Circuit Or Path
Description:
*/

#include <cstdio>
#include <vector>
#include <queue>

#define RANG 1000010
using namespace std;

struct tri {
	int nod, newn;
	bool marc;

	int nextn (int *x) {
		if (*x == nod)
			return newn;
		return nod;
	}
} A[RANG];

vector <int> ID[RANG];
queue <int> Q;
int v, a, nod, newn, impar, start = 1, G[RANG];

void Euler (int nod) {
	for (vector <int>::iterator id = ID[nod].begin(); id != ID[nod].end(); id++) {
		if (!A[*id].marc) {
			A[*id].marc = true;
			Euler (A[*id].nextn (&nod));
		}
	}
	Q.push (nod);
}

main() {
    freopen ("Euler.in", "r", stdin);
    freopen ("Euler.ou", "w", stdout);

	scanf ("%d %d", &v, &a);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d", &nod, &newn);
		ID[nod].push_back (i);
		ID[newn].push_back (i);
		A[i] = (tri) {nod, newn, false};
		G[nod]++;
		G[newn]++;
	}

	for (int i = 1; i <= v; i++)
		if (G[i] % 2) {
			impar++;
			start = i;
			if (impar > 2) {
				printf ("The Graph is not Eurelian\n");
				return 0;
			}
		}

	Euler (start);

	if (!impar)
		printf ("Eulerian Circuit\n");
	else
		printf ("Eulerian Path\n");
	for (; !Q.empty(); Q.pop())
		printf ("%d ", Q.front());
}
