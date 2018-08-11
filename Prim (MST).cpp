/*
Luis Enrique Bernal Fuentes
Algorithm: Prim 
Description: 
*/

#include <cstdio>
#include <vector>
#include <queue>

#define RANG 100
using namespace std;

typedef pair <int, int> two;
vector <two> A[RANG];
priority_queue <two, vector <two>, greater <two> > Q; 
bool M[RANG];
int n, a, newn, cost, nod, sol;

main() {
	freopen ("prim.in", "r", stdin);
	freopen ("prim.out", "w", stdout);
	
	scanf ("%d %d", &n, &a);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod].push_back (two (newn, cost));
		A[newn].push_back (two (nod, cost));
	}
	
	Q.push(two (0, 1));
	while (!Q.empty()) {
		nod = Q.top().second;
		cost = Q.top().first;
		Q.pop();
		if (!M[nod]) {
			M[nod] = true;
			sol += cost;
			for (vector<two>::iterator i = A[nod].begin(); i != A[nod].end(); i++)
				if (!M[i -> first])
					Q.push(two (i -> second, newn));
		}
	}
	
	printf ("%d\n", sol);
} 
