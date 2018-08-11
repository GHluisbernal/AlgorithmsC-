/*
Luis Enrique Bernal Fuentes
Algorithm: Gauus Comun Divisor
Description: 
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int a , b;

int GCD (int a, int b) {
	while (a) {
		swap (a, b);
		a %= b;
	}
	return b;
}

main () {
	freopen ("GCD.in", "r", stdin);
	freopen ("GCD.ou", "w", stdout);
	
	scanf ("%d %d", &a, &b);

	printf ("MCD es %d\n", GCD (a, b));
	printf ("MCM es %d\n", a * b / GCD (a, b));
}
