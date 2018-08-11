/*
Luis Enrique Bernal Fuentes
Algorithm: Range Min - Max Quering
Description:
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

#define RANG 1000000
using namespace std;

int n, c, p, q, a, b;
struct two {
	int min, max;
} T[RANG][19];

main() {
	freopen ("RMQ.in", "r", stdin);
	freopen ("RMQ.ou", "w", stdout);
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &T[i][0].min);
		T[i][0].max = T[i][0].min;
	}
	
	c = (int) log2 (n);
    a = n;
	for (int j = 1; j <= c; j++) {
		p = 1 << j - 1;
        a -= p;
		for (int i = 1; i <= a; i++) {
			T[i][j].min = min (T[i][j - 1].min, T[i + p][j - 1].min);
			T[i][j].max = max (T[i][j - 1].max, T[i + p][j - 1].max);
		}
	}
	
	scanf ("%d", &q);
	while (q--) {           
		scanf ("%d %d", &a, &b);
		c = (int) log2 (b - a);
		b = b - (1 << c) + 1;
		printf ("%d %d\n", min (T[a][c].min, T[b][c].min), max (T[a][c].max, T[b][c].max));
	}
	
	c = (int) log2 (n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++)
            printf ("%d//%d ", T[i][j].min, T[i][j].max);
        printf ("\n");
    }
}
