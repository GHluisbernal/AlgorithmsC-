/*
Luis Enrique Bernal Fuentes
Algorithm: Dijkstra
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

	bool operator < (const two &p) const {
		return cost > p.cost;
	}
};
vector <two> A[RANG];
priority_queue <two> Q;
int v, a, q, start, end, nod, newn, cost, C[RANG];

void BFS () {
	while (!Q.empty()) {
		nod = Q.top().newn;
		Q.pop();
		for (vector <two>::iterator i = A[nod].begin(); i != A[nod].end(); i++) {
			newn = i -> newn;
			cost = i -> cost + C[nod];
			if (C[newn] > cost) {
				C[newn] = cost;
				Q.push ((two) {newn, cost});
			}
		}
	}
}

main() {
	freopen ("Dijkstra.in", "r", stdin);
	freopen ("Dijkstra.ou", "w", stdout);

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
		Q.push ((two) {start, 0});
		BFS ();
		printf ("%d\n", C[end]);
	}
}
