/*
Luis Enrique Bernal Fuentes
Algorithm: Bridges
Description:
*/

#include <cstdio>
#include <vector>
#include <stack>

#define RANG 1000010
using namespace std;

struct tri {
	int nod, newn;
	bool marc;
	
	int nextn (int *a) {
		if (nod == *a)
			return newn;
		return nod;
	}
} A[RANG];

struct two {
	int nod, newn;
};

stack  <two> Q;
vector <int> ID[RANG]; 
int v, a, nod, newn, t, DT[RANG], LOW[RANG];

void Bridges (int nod) {
	DT[nod] = LOW[nod] = ++t;
	for (vector <int>::iterator id = ID[nod].begin(); id != ID[nod].end(); id++) {
		int newn = A[*id].nextn (&nod);
		if (!LOW[newn]) {
			A[*id].marc = true;
			Bridges (newn);
			LOW[nod] <?= LOW[newn];
			if (DT[nod] < LOW[newn])
				Q.push ((two) {nod, newn});
		}
		else
			if (!A[*id].marc)
				LOW[nod] <?= DT[newn];
	}
}

main() {
	freopen ("Bridges.in", "r", stdin);
	freopen ("Bridges.ou", "w", stdout);
	
	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d", &nod, &newn);
		A[i] = (tri) {nod, newn, false};
		ID[nod].push_back (i);
		ID[newn].push_back (i);
	}
	
	Bridges (1);
	
	while (!Q.empty()) {
		printf ("%d %d\n", Q.top().nod, Q.top().newn);
		Q.pop();
	}
}
