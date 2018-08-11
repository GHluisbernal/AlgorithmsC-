/*
Luis Enrique Bernal Fuentes
Algorithm: Big Mod (b^e) % m
Description:
*/

#include <cstdio>

using namespace std;

long long q, b, e, m, sq;

long long square (long long n) {
	return n * n;
}

long long big_mod (int b, int e, int m) {
	if (!e)
		return 1;
	if (e % 2 == 0)
		return square (big_mod (b, e / 2, m)) % m;
	return (b % m * big_mod (b, e - 1, m)) % m;
}

main () {
	scanf ("%d", &q);

	while (q--) {
		scanf ("%I64d %I64d %I64d", &b, &e, &m);
		printf ("%I64d\n", big_mod (b, e, m));
	}
}
