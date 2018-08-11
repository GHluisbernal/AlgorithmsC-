/*
Luis Enrique Bernal Fuentes
Algorithm: Fibonaci
Descriptions:
*/

#include <cstdio>

using namespace std;

int q, n;

//O (N)
long long slowfib (int n) {
	if (!n)
		return 0;
	long long l2 = 0, l1 = 1, sol = 1;
	for (int i = 2; i <= n; i++) {
		sol = l2 + l1;
		l2 = l1;
		l1 = sol;
	}
	return sol;
}

//O (log2 (N))
long long fastfib (int n) {
	long long t, i = 1, h = 1, j = 0, k = 0;
	while (n > 0) {
		if (n % 2) {
			t = j*h;
			j = i*h + j*k + t;
			i = i*k + t;
		}
		t = h*h;
		h = 2*k*h + t;
		k = k*k + t;
		n = (long long) n/2;
	}
	return j;
}

main () {
	scanf ("%d", &q);

	while (q--) {
		scanf ("%d", &n);
		printf ("%I64d\n", slowfib (n));
		printf ("%I64d\n", fastfib (n));
	}
}
