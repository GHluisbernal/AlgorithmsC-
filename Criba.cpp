/*
Luis Enrique Bernal Fuentes
Algorithm: Criba
Description:
*/

#include <cstdio>
#include <cmath>

#define RANG 1000010
using namespace std;

int l, sqrl;
bool MK[RANG];

main() {
	//freopen ("Criba.in", "r", stdin);
	//freopen ("Criba.ou", "w", stdout);

	scanf ("%d", &l);

	sqrl = (int) sqrt (l);
	for (int i = 2; i <= sqrl; i++)
		if (!MK[i]) {
			for (int j = i; j <= l; j += i)
				MK[j] = true;
			printf ("%d ", i);
		}
	for (int i = sqrl + 1; i <= l; i++)
		if (!MK[i])
			printf ("%d ", i);
}
