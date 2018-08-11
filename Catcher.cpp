/*
Luis Enrique Bernal Fuentes
Algorithm: Catcher
Description: 
*/

#include <cstdio>

#define RANG 5010
using namespace std;

int l, sol, H[RANG], C[RANG];

main() {
	freopen ("Catcher.in", "r", stdin);
	freopen ("Catcher.ou", "w", stdout);
	
	scanf ("%d", &l);
	for (int i = 1; i <= l; i++)
		scanf ("%d", &H[i]);

	C[l] = 1;
	for (int i = l - 1; i; i--) {
		for (int j = i + 1; j <= l; j++)
			if (H[i] >= H[j] && C[i] < C[j])
				C[i] = C[j];
		sol >?= ++C[i];
	}
	
	printf ("%d\n", sol);
}
