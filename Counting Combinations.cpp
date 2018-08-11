/*
Luis Enrique Bernal Fuentes
Algorithm: Counting Combinations C (n, k)
Description:
*/

#include <cstdio>

#define RANG 110
using namespace std;

long long q, n, k, T[RANG][RANG];

//O (n)
double comb (long long n, long long k) {
	double comb = 1;
	if (n - k < k)
		k = n - k;
	for (int i = 2; i <= k; i++)
		comb /= i;
	k = n - k;
	for (int i = n; i > k; i--)
		comb *= i;
	return comb + 0.01;
}

//O (k)
double combfast (long long n, long long k) {
    double comb = 1;
    if (n - k < k)
        k = n - k;
    for (int i = 1; i <= k; i++)
        comb = comb * (n - k + i) / i;
    return comb + 0.01;
}

//O (1)
long long pascal_tri (long long n, long long k) {
    return T[n][k];
}

main () {
	scanf ("%d", &q);

    for (int i = 0; i < RANG; i++)
        T[i][0] = T[i][i] = 1;
    for (int i = 1; i < RANG; i++)
        for (int j = 1; j < RANG; j++)
            T[i][j] = T[i - 1][j] + T[i - 1][j - 1];

	while (q--) {
		scanf ("%lld %lld", &n, &k);
		printf ("%0.lf\n", comb (n, k));
		printf ("%0.lf\n", combfast (n, k));
		printf ("%I64d\n", pascal_tri (n, k));
	}
}
