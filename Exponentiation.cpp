/*
Luis Enrique Bernal Fuentes
Algorithm: Exponentiation n^k
Descriptions:
*/

#include <cstdio>
#include <cmath>

using namespace std;

long long q, n, k;

long long square (long long n) {
	return n * n;
}

//O (N)
long long slowexp (long long n, long long k) {
	long long sol = 1;
	for (int i = 1; i <= k; i++)
		sol *= n;
	return sol;
}

//O (log2 (N))
long long fastexpr (long long n, long long k) {
	if (!k)
		return 1;
	if (k % 2 == 0)
		return square (fastexpr (n, k / 2));
	return n * fastexpr (n, k - 1);
}

//O (log2 (N))
long long fastexpi (long long n, long long k) {
    long long sol = 1;
    while (k) {
        if (k & 1)
            sol *= n;
        n *= n;
        k >>= 1;
    }
    return sol;
}


main () {
	scanf ("%lld", &q);

	while (q--) {
		scanf ("%lld %lld", &n, &k);
		printf ("%lld\n", slowexp (n, k));
		printf ("%lld\n", fastexpr (n, k));
		printf ("%lld\n", fastexpi (n, k));
		printf ("%0.lf\n", pow (n, (double) k));
		printf ("%0.lf\n", exp (log (0 ) * k));
	}
}
