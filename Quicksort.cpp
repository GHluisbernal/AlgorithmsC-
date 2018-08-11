/*
Luis Enrique Bernal Fuentes
Algorithm: Quicksort 
Description: 
*/

#include <cstdio>
#include <algorithm>

#define RANG 100
using namespace std;

int n;
int A[RANG];

void qcksort (int start, int end) {
    int s = start, e = end, piv = A[(s + e) / 2];
    do {
        while (A[s] < piv) s++;
        while (A[e] > piv) e--;
        if (s <= e) {
            swap (A[s], A[e]);
            s++; 
			e--;
        }
    } while (s < e);
    if (e > start) qcksort (start, e);
    if (s < end) qcksort (s, end);
}

main () {
    freopen ("Qcksort.in", "r", stdin);
    freopen ("Qcksort.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &A[i]);

    qcksort (0, n - 1);

    for (int i = 0; i < n; i++)
        printf ("%d ", A[i]);
} 

