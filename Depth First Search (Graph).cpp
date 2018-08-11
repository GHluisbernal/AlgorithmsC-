/*
Luis Enrique Bernal Fuentes
Algorithm: Depth First Search
Description: 
*/

#include <cstdio>
#include <vector>

#define RANG 1000010
#define oo 1 << 30
using namespace std;

struct two {
	int newn, cost;
};
vector <two> A[RANG];
int v, a, q, nod, newn, cost, C[RANG];

void DFS (int nod) {
	for (vector <two>::iterator i = A[nod].begin(); i != A[nod].end(); i++) {
		int newn = i -> newn;
		cost = i -> cost + C[nod];
		if (C[newn] > cost) {
			C[newn] = cost;
			DFS (newn);
		}
	}
}

main() {
	freopen ("DFS.in", "r", stdin);
	freopen ("DFS.ou", "w", stdout);
	
	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod].push_back ((two) {newn, cost});
	}
	
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &nod, &newn);
		fill (C, C + v + 1, oo);
		C[nod] = 0;
		DFS (nod);
		printf ("%d\n", C[newn]);
	}
}
