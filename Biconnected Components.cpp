/*
Luis Enrique Bernal Fuentes
Algorithm: Biconnected Components
Descriptions:
*/

#include <cstdio>
#include <vector>
#include <stack>

#define RANG 100010
using namespace std;

struct tri {
	int nod, newn;
	bool mk;

	bool operator != (const tri &p) {
		return nod != p.nod || newn != p.newn;
    }
} A[RANG];
vector <int> ID[RANG];
stack <tri> Q;
int v, a, t, nod, newn, DT[RANG], LOW[RANG];
bool MK[RANG];

void BC (int nod) {
	DT[nod] = LOW[nod] = ++t;
	for (vector <int>::iterator id = ID[nod].begin(); id != ID[nod].end(); id++) {
		int newn = A[*id].newn;
		if (!A[*id].mk) {
			A[*id].mk = true;
			Q.push (A[*id]);
		}
		if (!LOW[newn]) {
			BC (newn);
			LOW[nod] = min (LOW[nod], LOW[newn]);
			if (DT[nod] == LOW[nod] && !Q.empty()) {
				printf ("\n%d -> %d\n", Q.top().nod, Q.top().newn);
				MK[Q.top().nod] = true;
				MK[Q.top().newn] = true;
				Q.pop();
                while (!Q.empty() && ID[nod].size() && Q.top().newn != nod) {
					printf ("%d -> %d\n", Q.top().nod, Q.top().newn);
					MK[Q.top().nod] = true;
				     MK[Q.top().newn] = true;
					Q.pop();
				}
			}
		}
		else
		    if (!MK[newn])
			   LOW[nod] = min (LOW[nod], DT[newn]);
	}
	if (DT[nod] == LOW[nod] && !Q.empty()) {
                while (!Q.empty() && ID[nod].size() && Q.top().newn != nod) {
					printf ("%d -> %d\n", Q.top().nod, Q.top().newn);
					MK[Q.top().nod] = true;
				     MK[Q.top().newn] = true;
					Q.pop();
				}
			}
}

main () {
	freopen ("biconnected_components.in", "r", stdin);
	freopen ("biconnected_components.ou", "w", stdout);

	scanf ("%d %d", &v, &a);
	for (int i = 0; i < a; i++) {
		scanf ("%d %d", &nod, &newn);
		A[i] = (tri) {nod, newn, false};
		ID[nod].push_back (i);
	}

    for (int i = 1; i <= v; i++)
		if (!LOW[i])
			BC (i);
}
