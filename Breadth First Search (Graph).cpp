/*
Luis Enrique Bernal Fuentes
Algorithm: Breadth First Search
Description: 
*/

#include <cstdio>
#include <vector>
#include <queue>

#define RANG 1000010
#define oo 1 << 30
using namespace std;

struct two {
	int newn, cost;
};
vector <two> A[RANG];
queue <int> Q;
int v, a, q, start, end, nod, newn, cost, C[RANG];

void BFS () {
	while (!Q.empty()) {
		nod = Q.front();
		Q.pop();
		for (vector <two>::iterator i = A[nod].begin(); i != A[nod].end(); i++) {
			newn = i -> newn;
			cost = i -> cost + C[nod];
			if (C[newn] > cost) {
				C[newn] = cost;
				Q.push (newn);
			}
		}
	}
}

main() {
	freopen ("BFS.in", "r", stdin);
	freopen ("BFS.ou", "w", stdout);

	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod].push_back ((two) {newn, cost});
	}
	
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &start, &end);
		
		fill (C, C + v + 1, oo);
		C[start] = 0;
		Q.push (start);
		BFS ();
		printf ("%d\n", C[end]);
	}
}
