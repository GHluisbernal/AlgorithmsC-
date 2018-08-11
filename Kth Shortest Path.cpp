/*
Luis Enrique Bernal Fuentes
Algorithm: Kth Shortest Path
Description: 
*/

#include <cstdio>
#include <vector>
#include <queue>

#define RANG 1000010
using namespace std;

int n, a, start, end, k, nod, newn, newc, cost, lnod, V[RANG];
typedef pair <int, int> two;
vector <two> A[RANG];
priority_queue <two, vector <two>, greater <two> > Q;  

main() {
	freopen ("KSP.in", "r", stdin);
	freopen ("KSP.out", "w", stdout);
	
	scanf ("%d %d %d %d %d", &n, &a, &start, &end, &k);
	for (int i = 1; i <= a; i++) {
		scanf ("%d %d %d", &nod, &newn, &cost);
		A[nod].push_back(two (newn, cost));
		A[newn].push_back(two (nod, cost));
	}
	
	Q.push(two (0, start));
	while (!Q.empty()) {
		nod = Q.top().second;
		cost = Q.top().first;
		Q.pop();
		V[nod]++;
		
		if (nod == end) {
			printf ("%d\n", cost);
			if (V[nod] == k)
			   return 0;
		}
		lnod = A[nod].size();
		for (vector <two>::iterator i = A[nod].begin(); i != A[nod].end(); i++) {
			if (V[i -> first] < k) {
				newc = i -> second + cost;
				Q.push(two (newc, i -> first));
			}
		}
	}
	
	for (int i = V[end]; i <= k; i++)
		printf ("-1\n");
}
