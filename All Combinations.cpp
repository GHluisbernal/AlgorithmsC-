/*
Luis Enrique Bernal Fuentes
Algorithm: All Combinations
Description: 
*/

#include <cstdio>
#include <string>

#define RANG 30
#define p (1 << lW)
using namespace std;

int lW;
string S;
char W[RANG];

main() {
	freopen ("AC.in", "r", stdin);
	freopen ("AC.ou", "w", stdout);

	scanf ("%s\n", W);

	lW = strlen (W);
	printf ("%d\n", p - 1);
	for (int i = 1; i < p; i++) {
		S = "";
		for (int j = 0; j < lW; j++) 
			if (i & 1 << j)
				S += W[j];
		printf ("%s\n", S.c_str());
	}
}
