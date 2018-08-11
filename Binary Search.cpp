/*
Luis Enrique Bernal Fuentes
Algorithm: Binary Search
Description:
*/

#include <cstdio>

#define RANG 1000010
using namespace std;

int l, q, start, end, num, N[RANG];

int BS (int *start, int *end, int *num) {
	int piv = *end;
	while (N[piv] != *num && *start <= *end) {
		piv = *start + (*end - *start) / 2;
		if (N[piv] > *num)
			*end = piv - 1;
		else
			*start = piv + 1;
	}
	if (N[piv] == *num)
		return piv;
	return -1;
}

main () {
    freopen ("BS.in", "r", stdin);
    freopen ("BS.ou", "w", stdout);

	scanf ("%d", &l);
	for (int i = 1; i <= l; i++)
		scanf ("%d", &N[i]);

	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d %d", &start, &end, &num);
		printf ("%d\n", BS (&start, &end, &num));
	}
}

 
