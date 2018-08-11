/*
Luis Enrique Bernal Fuentes
Algorithm: Matrix Multiplication
Description:
*/

#include <cstdio>

#define RANG 5010
using namespace std;

int y, x, y1, x1, M1[RANG][RANG], M2[RANG][RANG], T[RANG][RANG];

bool MM (int *y, int *x, int *y1, int *x1) {
	if (*x != *y1)
		return false;
	
	for (int i = 1; i <= *y; i++)
		for (int j = 1; j <= *x1; j++)
			for (int k = 1; k <= *x; k++)
				T[i][j] += M1[i][k] * M2[k][j];
	return true;
}

main () {
	freopen ("MM.in", "r", stdin);
	freopen ("MM.ou", "w", stdout);
	
	scanf ("%d %d %d %d", &y, &x, &y1, &x1);
	for (int i = 1; i <= y; i++)
		for (int j = 1; j <= x; j++)
			scanf ("%d", &M1[i][j]);
	
	for (int i = 1; i <= y1; i++)
		for (int j = 1; j <= x1; j++)
			scanf ("%d", &M2[i][j]);
	
	if (MM (&y, &x, &y1, &x1)) {
		printf ("Las Matrices Se Pueden Multiplicar\n");
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j < x1; j++)
				printf ("%d ", T[i][j]); 
			printf ("%d\n", T[i][x1]);
		}
	}
	else
		printf ("Las Matrices Son Incompatibles\n");
}
