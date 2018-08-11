/*
Luis Enrique Bernal Fuentes
Algorithm: Trie
Description:
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define RANG 256
using namespace std;

struct trie {
	bool marc;
	trie *next[RANG];
} TRIE, *P;
int l, k, q, lW;
char W[RANG];

main () {
	freopen ("Trie.in", "r", stdin);
	freopen ("Trie.ou", "w", stdout);

	scanf ("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf ("%s", &W);

		P = &TRIE;
		lW = strlen (W);
		for (int j = 0; j < lW; j++) {
			if (P -> next[W[j]] == NULL) {
				P -> next[W[j]] = new trie();
				P = P -> next[W[j]];
			}
			else
				P = P -> next[W[j]];
		}
		P -> marc = true;
	}

	scanf ("%d", &q);
	while (q--) {
		scanf ("%s", &W);
		P = &TRIE;
		lW = strlen (W);
		for (k = 0; k < lW; k++) {
			if (P -> next[W[k]] == NULL)
				break;
			P = P -> next[W[k]];
		}

		if (k == lW && P -> marc)
			printf ("YES\n");
		else
			printf ("NO\n");
	}
}
