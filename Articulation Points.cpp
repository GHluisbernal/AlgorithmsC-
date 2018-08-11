/*
Luis Enrique Bernal Fuentes
Algorithm: Articulations Points
Description:
*/

#include <cstdio>
#include <vector>
#include <stack>

#define RANG 1000010
using namespace std;

vector <int> A[RANG];
stack <int> Q;
int v, a, nod, newn, t, DT[RANG], LOW[RANG];
bool MK[RANG];

void AP (int nod) {
	DT[nod] = LOW[nod] = ++t;
	for (vector <int>::iterator newn = A[nod].begin(); newn != A[nod].end(); newn++) {
		if (!LOW[*newn]) {
			AP (*newn);
			LOW[nod] = min (LOW[nod], LOW[*newn]);
			if (!MK[nod] && (DT[nod] != 1 && DT[nod] <= LOW[*newn]) || (DT[nod] == 1 && DT[*newn] > 2)) {
				MK[nod] = true;
				Q.push (nod);
			}
		}
		else
			LOW[nod] = min (LOW[nod], DT[*newn]);
	}
}

main() {
	freopen ("AP.in", "r", stdin);
	freopen ("AP.ou", "w", stdout);

	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d", &nod, &newn);
		A[nod].push_back (newn);
		A[newn].push_back (nod);
	}

	AP (1);

	while (!Q.empty()) {
		printf ("%d\n", Q.top());
		Q.pop();
	}
}
