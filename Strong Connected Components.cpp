/*
Luis Enrique Bernal Fuentes
Algorithm: Strong Connected Components
Description: 
*/

#include <cstdio>
#include <vector>
#include <stack>

#define RANG 1000010
using namespace std;

vector <int> A[RANG];
stack <int> Q;
int v, a, t, nod, newn, LOW[RANG], DT[RANG];
bool MK[RANG];

void SCC (int nod) {
    DT[nod] = LOW[nod] = ++t;
    Q.push (nod);
    for (vector <int>::iterator newn = A[nod].begin(); newn != A[nod].end(); newn++) {
        if (!LOW[*newn]) {
            SCC (*newn);
            LOW[nod] = min (LOW[nod],LOW[*newn]);
        }
        else
            if (!MK[*newn])
                LOW[nod] = min (LOW[nod], DT[*newn]);
    }

    if (LOW[nod] == DT[nod]) {
		while (Q.top() != nod) {
			printf ("%d ", Q.top());
			MK[Q.top()] = true;
			Q.pop();
		}
        printf ("%d\n", Q.top());
		MK[nod] = true;
		Q.pop();
    }
}

main() {
    freopen ("SCC.in", "r", stdin);
    freopen ("SCC.ou", "w", stdout);

    scanf ("%d %d", &v, &a);
    for (int i = 1; i <= a; i++) {
        scanf ("%d %d", &nod, &newn);
        A[nod].push_back (newn);
    }
    
	for (int i = 1; i <= v; i++)
		if (!LOW[i])
			SCC (i);
}


