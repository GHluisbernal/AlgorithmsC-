/*
Luis Enrique Bernal Fuentes
Algorithm: Kruskal (MST) with Disjoin SET
Descriptions:
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int v, a, nod, newn, cost, setnod, setnewn, sol, SET[RANG], R[RANG];
struct tri {
    int nod, newn, cost;

	bool operator < (const tri &p) const {
		return cost < p.cost;
	}
} A[RANG];

void make_set (int i) {
	SET[i] = i;
	R[i] = 1;
}

int find_set (int nod) {
	if (SET[nod] != nod)
		SET[nod] = find_set (SET[nod]);
	return SET[nod];
}

void join_set (int nod, int newn) {
	if (R[nod] > R[newn]) {
		SET[newn] = nod;
		R[nod]++;
	}
	else {
		SET[nod] = newn;
		R[newn]++;
	}
}

main() {
	freopen ("kruskal.in", "r", stdin);
	freopen ("kruskal.out", "w", stdout);
	
	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[i] = (tri) {nod, newn, cost}; 
	}
	
	sort (A, A + a);
	for (int i = 1; i <= v; i++)
		make_set (i);
	
	for (int i = 0; i < a; i++) {
		setnod = find_set (A[i].nod);
		setnewn = find_set (A[i].newn);
		if (setnod != setnewn) {
			sol += A[i].cost;
			join_set (setnod, setnewn);
		}
	}
	
	printf ("%d\n", sol);
}
